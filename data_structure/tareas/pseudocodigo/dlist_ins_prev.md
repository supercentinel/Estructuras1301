# Insertar nodo en el nodo previo

## Si el nodo es la caebeza

![diagramamaCabeza](../assets/DiagramaCabeza.png)

```
Nuevo->prev = Head->prev
Nuevo->next = Head
Head->prev = Nuevo
Nuevo->prev = NULL
```