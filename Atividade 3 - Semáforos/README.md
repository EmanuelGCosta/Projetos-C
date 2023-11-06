<h1 align="center" font-weight: bold;"> Semáforos 🚦</h1>

## Descrição
>O código simula um cruzamento com semáforos alternando entre os estados "aberto" e "fechado".
>As threads juntamente com o Mutex garantem que as mudanças de estado ocorram de maneira ordenada e evitam condições de corrida.
>
>Caso não existisse a exclusão mútua e a função sleep, os semáforos iriam trocar de estado rapidamente, porém,
>os dois trabalham juntos para que a troca seja coordenada
