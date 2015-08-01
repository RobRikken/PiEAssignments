function [ output_args ] = VerletsMethod( FunctionString, StartPoint, StepSize, EndPoint, InitialCondition )
%VERLETSMETHOD Summary of this function goes here
%   Detailed explanation goes here

    NumberOfSteps = (StartPoint - EndPoint) / StepSize;

    Abscissas = StartPoint : StepSize : EndPoint;
    Ordinates = zeros(1 : NumberOfSteps);
    Ordinates(1) = InitialCondition;

    for i = 1 : NumberOfSteps
        Ordinates(1 + i) = Ordinates(i) + StepSize * feval(FunctionString, Ordinates(i), Abscissas(i));
    end
end
end

