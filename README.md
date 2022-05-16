# sat_sim
Simple simulation of communicaiotn betwenn satelite and earth station 

# Conan

$ pip install conan

# project/build
$ cd build/
$ conan install .. --build=missing


# Commands to build
# in project/build
$ cmake -DCMAKE_MODULE_PATH="$(pwd)" ..
$ cmake --build .


# Execute
# in project/build/bin
$ cd bin
$ ./sat_sys


# Description
sat_sys binary will lauch 2 server sockets emulating satelites, in the object estacion terrena client socket will be luch to commuicate with each server (2 as example).
You can add several satelite object (assign port wisely) and create several task. Add those to the object estacion terrena and it will do all the job.

On execution this will show:

Estacion terrena: myEst
Tareas:
name=mantenimiento, recursos=[1,2,], payoff=1
name=fsck, recursos=[1,6,], payoff=0.1
name=pruebas, recursos=[5,6,], payoff=1
name=fotos, recursos=[1,5,], payoff=10
Satelites:
Satelite_1, puerto=5000, tareas=[]
Satelite_2, puerto=5001, tareas=[]
Conectado a Satelite_1 at port 5000
Conectado a Satelite_2 at port 5001
Tareas por satelite:
Satelite_1, puerto=5000, tareas=[fsck,]
Ejecutando...
Esperando respuesta...
Recibi 'FAIL'
Satelite_2, puerto=5001, tareas=[pruebas,mantenimiento,]
Ejecutando...
Esperando respuesta...
Recibi 'FAIL'
Esperando respuesta...
Recibi 'SUCCESS'
Socket closed (Satelite_1).
Se detuvo conexion a Satelite_1 at port 5000
Socket closed (Satelite_2).
Se detuvo conexion a Satelite_2 at port 5001
SAT Satelite_1: Iniciando en puerto 5000
SAT Satelite_1: Listening ...
SAT Satelite_1: Socket paired.
SAT Satelite_1: Len: 100.
SAT Satelite_1: fsck 0.1 [1,6,]
SAT Satelite_1: procesando ...
SAT Satelite_1: Error on read.
SAT Satelite_1: Cerrando conexión...
SAT Satelite_1: END.
SAT Satelite_2: Iniciando en puerto 5001
SAT Satelite_2: Listening ...
SAT Satelite_2: Socket paired.
SAT Satelite_2: Len: 100.
SAT Satelite_2: pruebas 1.0 [5,6,]
SAT Satelite_2: procesando ...
SAT Satelite_2: Len: 100.
SAT Satelite_2: mantenimiento 1.0 [1,2,]
SAT Satelite_2: procesando ...
SAT Satelite_2: Error on read.
SAT Satelite_2: Cerrando conexión...
SAT Satelite_2: END.
Fin.

"SAT X:" indicates a message communicated by the sat with name X.

You can find a docker image in https://hub.docker.com/r/ivleneb/sat_sim
 

