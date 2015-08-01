function [ PotentialV, Repulsion, Attraction ] = LennardJonesPotential( Epsilon, Sigma, ParticleDistance )
%LENNARDJONESPOTENTIAL Atomic particals model
% The Lennard-Jones potential is a mathemathical model to approximate the
% interaction between a pair of neutral atoms or molecules

Repulsion = RepulsiveTerm(Sigma, ParticleDistance);
Attraction = AttractiveTerm(Sigma, ParticleDistance);
PotentialV = 4 .* Epsilon .* ( Repulsion - Attraction);

end

function Repulsion = RepulsiveTerm(Sigma, ParticleDistance)
%Describes Pauli repulsion at short range
Repulsion = (Sigma ./ ParticleDistance).^12;
end

function Attraction = AttractiveTerm(Sigma, ParticleDistance)
%Van der Waals attraction force at long range
Attraction = (Sigma ./ ParticleDistance).^6;
end