/*
 * Particle.cpp
 *
 *  Created on: 9 May 2017
 *      Author: Raja
 */

#include "Particle.h"
#include <stdlib.h>
#include <math.h>
namespace cop {

Particle::Particle(): m_x(0), m_y(0) {

	m_direction = (2 * M_PI * rand())/RAND_MAX;
	m_speed = (0.001 * rand())/RAND_MAX;

}

void Particle::update() {

	double xspeed = m_speed * cos(m_direction);
	double yspeed = m_speed * sin(m_direction);

	m_x += xspeed;
	m_y += yspeed;
	}




Particle::~Particle() {
} /* namespace cop */

}
