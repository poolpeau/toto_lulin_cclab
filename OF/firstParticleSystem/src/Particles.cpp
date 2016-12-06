//
//  Particles.cpp
//  firstParticleSystem
//
//  Created by TtTtTtTtT on 03/11/16.
//
//

#include "Particles.hpp"


Particle::Particle(ofVec2f pos){
    mPosition = pos;
    mVelocity = ofVec2f(ofRandom (-2,f,2.f),)

}


void Particle:: resetForces(){

}

void Particle::applyForces(){

}

void Particle::update(){
    
    mVelocity+= mAcceleration;
    mPosition+= mVelocity

}