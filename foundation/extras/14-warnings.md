## **lista de cuidados essenciais ao programar em C**

### **manipulação de strings e entrada/saída**

1. **`scanf()` deixa o `\n` no buffer.**
   * sempre use `getchar()` ou `fflush(stdin)` (com cuidado, não é padrão) depois de `scanf()` para limpar o buffer.
   * dica: implemente uma função que limpa o buffer com `getchar()`
   * sempre use `fgets()` para ler strings ao invés de `scanf("%s")`.

2. **`fgets()` inclui o `\n` na string se houver espaço.**
   * sempre use `strcspn()` ou um loop manual para remover o `\n`:
     ```c
     str[strcspn(str, "\n")] = '\0';
     ```

3. **`strncpy()` não garante terminador nulo (`\0`).**
   * sempre garanta o terminador:
     ```c
     strncpy(dest, src, n); // n é o tamanho
     dest[n - 1] = '\0';  // cuidado extra!
     ```

4. **não use `%s` em `scanf` para strings se não souber o tamanho.**
   * pode causar *buffer overflow*.
   * prefira `fgets()` com `stdin`.

5. **nunca confie em entrada do usuário.**
   * sempre valide se `scanf`, `fgets`, ou qualquer função retornou sucesso antes de usar os dados.

---

### **alocação dinâmica (malloc, realloc, free)**

6. **sempre verifique se `malloc`, `calloc` ou `realloc` retornaram `NULL`.**
   * evita *segmentation fault*.
   ```c
   ptr = malloc(n * sizeof(int));
   if (!ptr) {
       // tratar erro
   }
   ```

7. **sempre use `free()` quando terminar de usar uma memória alocada dinamicamente.**
   * evita *memory leak*.

8. **evite *memory leak* em `realloc`:**
   * não faça `ptr = realloc(ptr, novo_tam);` diretamente.
   * prefira:
     ```c
     void *tmp = realloc(ptr, novo_tam);
     if (tmp) ptr = tmp;
     else {
         // tratar erro sem perder ptr original
     }
     ```

9. **não use memória após `free()`.**
   * isso é *undefined behavior*.

10. **zere ponteiros após liberar:**
   * agora o ponteiro pode ser reutilizado
    ```c
    free(ptr);
    ptr = NULL;
    ```

---

### **ponteiros e arrays**

11. **cuidado ao usar ponteiros sem inicializar.**
* ponteiros não inicializados apontam pra lugar aleatório.

12. **arrays não carregam informação de tamanho.**
* sempre passe o tamanho como argumento para funções que os manipulam.
* se lembre que um argumento passado como parâmetro nunca será modificado fora da função (no `main()`)
* se quiser que o argumento seja atualizado dentro da função, passe um ponteiro como parâmetro, e dentro da funçaõ atualize seu valor

13. **ao usar ponteiro de ponteiro (`int **`), aloque os dois níveis corretamente.**
```c
int **matriz = malloc(linhas * sizeof(int *));
for (int i = 0; i < linhas; i++)
    matriz[i] = malloc(colunas * sizeof(int));
```

14. **evite usar ponteiros após `realloc`, pois eles podem ter sido movidos.**
* é importante verificar a necessidade de retornar um novo ponteiro para atualizar o ponteiro original

---

### 🧠 **outros detalhes perigosos**

15. **não esqueça o `return 0;` no `main()` (ou outro valor em caso de erro).**

16. **sempre inicialize variáveis locais antes de usar.**

17. **cuidado com o índice fora dos limites do array.**
* C não vai reclamar, só vai causar bugs invisíveis.

18. **evite funções perigosas como `gets()` e `scanf("%s")`.**
* são vulneráveis a overflow.

19. **evite usar `fflush(stdin)` em ambientes portáveis.**
* comportamento indefinido fora do MSVC.

20. **não modifique string literais.**
```c
char *s = "teste";  // NÃO FAÇA: s[0] = 'T'; --> crash
```
* use `char s[] = "teste";` se quiser modificar.


