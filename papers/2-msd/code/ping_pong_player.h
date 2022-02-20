#if !defined ping_pong_player_h
#define ping_pong_player_h

#include "simulator.h"
#include "event.h"
#include "stdarg.h"

class ping_pong_player: public Simulator {
	double state;
	double sigma;
	char* name;
	double y[10];
	double speed;

	#define INF 1e20
	#define SEND 1
	#define RECEIVE 0