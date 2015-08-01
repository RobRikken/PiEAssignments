function [ Force ] = InteractionForce( Sigma, Epsilon, ParticleDistance )
%INTERACTIONFORCE Calculates force between particles
%This is the differentiated function of the Lennard-Jones potential
%mathematical model together with a unit vector.

UnitVector = 1;

Force = - 4 .* Epsilon .* ((6 .* Sigma .^6) ./ ParticleDistance .^7 - ...
    (12 .* Sigma .^12) ./ ParticleDistance .^13) .* UnitVector;

end