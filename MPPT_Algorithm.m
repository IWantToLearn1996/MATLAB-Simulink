function D = fcn(V_PV, I_PV)

% Initial Duty Cycle with Max and Min Limits 
Dinit = 0.5;
Dmax = 0.9;
Dmin = 0.1;
deltaD = 20e-6;


%Persistent Variables are LOCAL to the Function
persistent Vold Pold Dold;

dataType = "double";

%Initialize these Parameters
if isempty(Vold)
    Vold = 0;
    Pold = 0;
    Dold = Dinit;
end

%P Calculation
P = V_PV * I_PV;
dV = V_PV - Vold;
dP = P - Pold;

%dP<0, dV<0 then Decrease D
%dP<0, dV>0 then Increase D
%dP>0, dV<0 then Increase D
%dP>0, dV>0 then Decrease D
if dP ~= 0 
    if dP < 0
        if dV < 0 
            D = Dold - deltaD;
        else
            D = Dold + deltaD;
        end
        else
        if dV < 0
            D = Dold + deltaD;
        else
            D = Dold - deltaD;
        end
    end
%dP=0 then takes the Old value
    else D = Dold;
end

%if D is more than Max and less than Min then takes the Old Value
if D >= Dmax || D <= Dmin
    D = Dold;
end

%Values Update
Vold = V_PV;
Pold = P;
Dold = D;
