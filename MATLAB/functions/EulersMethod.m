function [ Ordinates, Abscissas ] = EulersMethod( FunctionString, StartPoint, StepSize, EndPoint, InitialCondition)
%EULERSMETHOD Uses Eulers method to approximate a differential equation

    NumberOfSteps = (StartPoint - EndPoint) / StepSize;

    Abscissas = StartPoint : StepSize : EndPoint;
    Ordinates = zeros(1 : NumberOfSteps);
    Ordinates(1) = InitialCondition;

    for i = 1 : NumberOfSteps
        Ordinates(1 + i) = Ordinates(i) + StepSize * feval(FunctionString, Ordinates(i), Abscissas(i));
    end
end