# Simulation of Continuous and Discrete Systems

## Continuous Function Illustration
```
         f(x)
           |
         9 |                *
           |             *
         4 |          * 
           |       *
         1 |    *
           |  *
         0 +------------------> x
            0   1   2   3   4
```

## Discrete System Illustration
```
    y[n]
     |
  10|        *       *       *       *
     |
    8|    *       *       *       *
     |
    6|       *       *       *
     |
    4| *       *       *       *
     |
    2|   *       *       *
     +----------------------------------> n
        0   1   2   3   4   5   6   7
```

## Analog Method of System Simulation
>- Aanalog computers are those computers that are unified with devices like adder and integral so as to simulate the continuous mathematical model of the system which generates continuous output.
>- Analog method of system simulation is for use of analog computers and other analog devices in the simulation of continuous systems.
>- The analog computation is sometimes called differential analyzer. Electronics analog computers for simulation are based on the use of high gain dc amplifiers called operational amplifiers. (Op-amps)
>- In such analog computers, voltages are equated to mathematical variables and the op-amps can add and integrate these voltages.
>- The proper configuration can handle addition of several input voltages each representing the input variables.
>- The general method to apply analog computers for the simulation of continuous system models involve following components.


#### Integrator
```
    +--------+
--->|   ∫    | --->
    +--------+
```

#### Summer (Three Instances)
```
    +-----------+
--->|           |
--->|    Σ      | --->
--->|           |
    +-----------+
```

#### Differentiator
```
    +-----------+
--->|   d/dt    | --->
    +-----------+
```

#### Inverter
```
    +-----------+
--->|   -1 ×    | --->
    +-----------+
```

#### Multiplier
```
    +-----------+
--->|           |
    |     ×     |--->
--->|           |
    +-----------+
```

#### Divider
```
           +-----------+
---------->|           |
Numerator  |           | 
           |     ÷     |--->
---------->|           |
Denominator|           |
           +-----------+
```

### Example : Automatic Suspension Problem
> The general method by which analog computers are applied can be demonstrated by the second order differential equation

                            Mx'' + Dx' + Kx = KF(t)

Solving the equation for the highest order derivative gives

                           Mx'' = KF(t) - Dx' - Kx

>>>>>>>>>>>>>>>>>> Diagrammmmmmmmmm Neeededddddddd


Fig: Automobile Suspension System

Suppose a variable representing the input F(t) is supplied, assume there exists variables representing -x, x'. These three variables can be scaled and added to produce `Mx''`. Integrating it with a scale factor `1/M` produces x'. Changing sign produces -x', further integrating produces -x, a further sign inverter is included to produce +x as an output.