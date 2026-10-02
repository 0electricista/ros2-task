# ros2-task

Pequeña modificación sobre `demo_nodes_cpp` para encadenar tres nodos ROS 2:

- `talker` genera y publica números primos cada segundo en el tópico `chatter`
  (`std_msgs/msg/String`).
- `number_processor` recibe esos mensajes, eleva el primo al cuadrado y publica
  el resultado en `processed_data`.
- `listener` recibe los resultados procesados desde `processed_data` y los
  muestra por consola.

El launch incluido inicia los tres nodos:

```bash
ros2 launch demo_nodes_cpp topics/number_processor.launch.py
```
