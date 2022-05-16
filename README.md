# sat_sim
Simple simulation of communicaiotn betwenn satelite and earth station 
<br>
# Project build
$ pip install conan <br>
$ git clone https://github.com/ivleneb/sat_sim.git project <br>
$ cd project/build/ <br>
$ conan install .. --build=missing <br>
<br>
... in project/build <br>
$ cmake -DCMAKE_MODULE_PATH="$(pwd)" .. <br>
$ cmake --build . <br>
<br>
# Execute
... in project/build/
$ cd bin <br>
$ ./sat_sys <br>
<br>
... Description<br>
sat_sys binary will lauch 2 server sockets emulating satelites, in the object estacion terrena client socket will be luch to commuicate with each server (2 as example).
You can add several satelite object (assign port wisely) and create several task. Add those to the object estacion terrena and it will do all the job.
<br>
On execution this will show:<br>
<br>
Estacion terrena: myEst <br>
Tareas: <br>
name=mantenimiento, recursos=[1,2,], payoff=1 <br>
name=fsck, recursos=[1,6,], payoff=0.1<br>
name=pruebas, recursos=[5,6,], payoff=1<br>
name=fotos, recursos=[1,5,], payoff=10<br>
Satelites:<br>
Satelite_1, puerto=5000, tareas=[]<br>
Satelite_2, puerto=5001, tareas=[]<br>
Conectado a Satelite_1 at port 5000<br>
Conectado a Satelite_2 at port 5001<br>
Tareas por satelite:<br>
Satelite_1, puerto=5000, tareas=[fsck,]<br>
Ejecutando...<br>
Esperando respuesta...<br>
Recibi 'FAIL'<br>
Satelite_2, puerto=5001, tareas=[pruebas,mantenimiento,]<br>
Ejecutando...<br>
Esperando respuesta...<br>
Recibi 'FAIL'<br>
Esperando respuesta...<br>
Recibi 'SUCCESS'<br>
Socket closed (Satelite_1).<br>
Se detuvo conexion a Satelite_1 at port 5000<br>
Socket closed (Satelite_2).<br>
Se detuvo conexion a Satelite_2 at port 5001<br>
SAT Satelite_1: Iniciando en puerto 5000<br>
SAT Satelite_1: Listening ...<br>
SAT Satelite_1: Socket paired.<br>
SAT Satelite_1: Len: 100.<br>
SAT Satelite_1: fsck 0.1 [1,6,]<br>
SAT Satelite_1: procesando ...<br>
SAT Satelite_1: Error on read.<br>
SAT Satelite_1: Cerrando conexión...<br>
SAT Satelite_1: END.<br>
SAT Satelite_2: Iniciando en puerto 5001<br>
SAT Satelite_2: Listening ...<br>
SAT Satelite_2: Socket paired.<br>
SAT Satelite_2: Len: 100.<br>
SAT Satelite_2: pruebas 1.0 [5,6,]<br>
SAT Satelite_2: procesando ...<br>
SAT Satelite_2: Len: 100.<br>
SAT Satelite_2: mantenimiento 1.0 [1,2,]<br>
SAT Satelite_2: procesando ...<br>
SAT Satelite_2: Error on read.<br>
SAT Satelite_2: Cerrando conexión...<br>
SAT Satelite_2: END.<br>
Fin.<br>
<br>
"SAT X:" indicates a message communicated by the sat with name X.<br>
<br>
You can find a docker image in https://hub.docker.com/r/ivleneb/sat_sim
 

