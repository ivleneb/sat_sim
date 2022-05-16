#include "task.h"
#include <vector>
#include <algorithm>

Task::Task(){
	attended=false;
}

Task::Task(std::string nombre, float pago, std::vector<int> recursos)
: name(nombre), payoff(pago), attended(false), resources(recursos) {
}

void Task::setName(std::string nombre){
	name=nombre;
}

std::string Task::getName(void){
	return name;
}

void Task::setPayoff(float pago){
	payoff=pago;
}

float Task::getPayoff(void){
	return payoff;
}

// verifica si la tarea usa un recurso en especifico
bool Task::hasResource(int r){
	if (std::find(resources.begin(), resources.end(), r)!=resources.end())
		return true;
	else return false;
}

// Operator overload para el ordenamiento de acuerdo a payload
bool Task::operator<(const Task&  t2){
	return payoff<t2.payoff;
}

std::ostream& operator << (std::ostream &out, const Task &t){
	out<<"name="<<t.name<<", recursos=[";
	for(auto& i:t.resources){
		out<<i<<",";
	}
	out<<"], payoff="<<t.payoff;
	return out;
}

void Task::setAttended(){
	attended=true;
}

bool Task::isAttended(){
	return attended;
}
