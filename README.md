Bueno... la idea de esto era crear un sistema de comandos para el input, usando Allegro5 y un joystick.
Básicamente hago un InputHandler con un Swap() para intercambiar botones y una clase base Command de donde derivan los comandos.
Después le mando un bucle while que detecta eventos del joy con Allegro y los manda al handler, que devuelve un comando para ejecutar.
Obviamente esto después debería hacerse más complejo, como cuando le agregue un Actor o un Player, pero dejo esto como una base interesante.#   C o m m a n d P a t t e r n  
 