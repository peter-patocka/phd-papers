#include "ping_pong_player.h"

void ping_pong_player::init(double t,...) {
	//The 'parameters' variable contains the parameters transferred from the editor.
	va_list parameters;
	va_start(parameters,t);

	name=va_arg(parameters,char*);
	speed=va_arg(parameters,double);
	state=0;
	sigma=INF;
	printLog("[%s] init(state=%0.0f,sigma=%0.1f,speed=%0.2f)\n", name, state, sigma, speed);
}

double ping_pong_player::ta(double t) {
	printLog("[%s] time_advance(state=%0.0f)=%0.2f\n", name, state, sigma);
	return sigma;
}

void ping_pong_player::dint(double t) {
	double oldState = state;
	double oldSigma = sigma;
	if(state==SEND) {
		state=0;
		sigma=INF;
	}
	printLog("[%s] delta_internal(state=%0.0f,sigma=%0.2f)=(state=%0.0f,sigma=%0.2f)\n", name, oldState, oldSigma, state, sigma);
}

void ping_pong_player::dext(Event x, double t) {
	double *u=(double*)x.value;
	double oldState = state;
	double oldSigma = sigma;
	if (u[0] == SEND) {
		state=u[0];
		sigma=speed;
	}
	printLog("[%s] delta_external(state=%0.0f,sigma=%0.2f,x=%f)=(state=%0.0f,sigma=%0.2f)\n", name, oldState, oldSigma, u[0], state, sigma);
}

Event ping_pong_player::lambda(double t) {
	y[0]=SEND;
	printLog("[%s] lambda(state=%0.0f,sigma=%0.2f)=%0.0f\n", name, state, sigma, SEND);
	return Event(&y,0);
}

void ping_pong_player::exit() {
}