%Plot of the potential between two particles. Question 1
ParticleDistances = 0.88 : 0.0001 : 3; % started at 0.88 because of plot size
Sigma = 1;
Epsilon = 1;
[ PotentialV, Repulsion, Attraction ] = LennardJonesPotential( Epsilon, Sigma, ParticleDistances );
plot(ParticleDistances, PotentialV, ParticleDistances, Repulsion, ParticleDistances, Attraction);

%Plot of the force between particles. Question 3
% 
% [ Force ] = InteractionForce( Sigma, Epsilon, ParticleDistances );
% plot(Force);