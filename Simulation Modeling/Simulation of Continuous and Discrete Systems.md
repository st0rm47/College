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
---

## Analog Method of System Simulation
- Analog computers are those computers that are unified with devices like adder and integral so as to simulate the continuous mathematical model of the system which generates continuous output.
- Analog method of system simulation is for use of analog computers and other analog devices in the simulation of continuous systems.
- The analog computation is sometimes called differential analyzer. Electronics analog computers for simulation are based on the use of high gain dc amplifiers called operational amplifiers. (Op-amps)
- In such analog computers, voltages are equated to mathematical variables and the op-amps can add and integrate these voltages.
- The proper configuration can handle addition of several input voltages each representing the input variables.
- The general method to apply analog computers for the simulation of continuous system models involve following components:


    > #### Integrator
    ```
        +--------+
    --->|   ∫    | --->
        +--------+
    ```

    > #### Summer (Three Instances)
    ```
        +-----------+
    --->|           |
    --->|     Σ     | --->
    --->|           |
        +-----------+
    ```

    > #### Differentiator
    ```
        +-----------+
    --->|   d/dt    | --->
        +-----------+
    ```

    > #### Inverter
    ```
        +-----------+
    --->|     -     | --->
        +-----------+
    ```

    > #### Multiplier
    ```
        +-----------+
    --->| A         |
        |     ×     |--->
    --->| B         |
        +-----------+
    ```

    > #### Divider
    ```
        +-----------+
    --->|A          |
        |     ÷     |--->
    --->|B          |
        +-----------+
    ```
    ---

    ***Example : Automatic Suspension Problem***

    The general method by which analog computers are applied can be demonstrated by the second order differential equation
    ``` math
    Mx'' + Dx' + Kx = KF(t)
    ```
    Solving the equation for the highest order derivative gives
    ``` math
    Mx'' = KF(t) - Dx' - Kx
    ```
    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Diagram Needed


    Fig: Automobile Suspension System

    Suppose a variable representing the input *`F(t)`* is supplied, assume there exists variables representing *`-x`*, *`-x'`*. These three variables can be scaled and added to produce `Mx''`. Integrating it with a scale factor *`1/M`* produces *`x'`*. Changing sign produces *`-x'`*, further integrating produces *`-x`*, a further sign inverter is included to produce *`+x`* as an output.
---


## Continuous System Models
- A continuous system is one in which the predominant activities of the system cause smooth changes in the attributes of the system entities. 
- When such a system is modelled mathematically the variables of the model representing the attributes are controlled by the continuous system.
- More generally in a continuous system the relationship describes the rate at which the variables representing the attributes change, so that the model circuit of differential equation. 
---

## Differential and partial differential equation

> ### Differential Equation:
- A differential equation is an equation involving an unknown function and its derivative.
- The order of the differential equation is the order of the highest derivative of the unknown function involved in the equation.
```math
\frac{dy}{dt} = f(y,t) ...........................\text{(i)}
```
---

> ### Linear Differential Equation
- A linear differential equation of order `n` is a differential equation written in the following form.
    ```math
    a_n(x) \frac{d_ny}{dx^n} + a_{(n-1)}(x) + \frac{d_{(n-1)}(y)}{dx^(n-1)} + ... +a_1(x) \frac{dy}{dx}+ a_0(x)y = f(x)
    ```

    where `a_n(x), a_(n-1)(x), a_1(x), a_0(x)` are functions of `x` and `f(x)` is a function of `x`.
--- 

> ### Partial Differential Equation
- When more than one independent variable occur in a differential equation the equation is said to be partial differential equation.

    ***Example***:
    - An equation describing the flow of heat in a three-dimensional body. There are four independent variables, representing the three dimensions and time and one dependent variable representing temperatures.

    - The general heat conduction equation:
``` math
        \frac{d}{dx}(k.(\frac{dT}{dx})) + \frac{d}{dy}(k.(\frac{dT}{dy})) + \frac{d}{dz}(k.(\frac{dT}{dz})) + qv = \rho \space C_p \frac{dT}{dt}
```
- where k is the material conductivity.
- $qv$ is the rate at which energy is generated per unit volume of the medium.
- $\rho$ is the density
- $C_p$ is the specific heat capacity.

    This equation is also known as the Fourier-Biot equation and provides the basic tool for heat conduction analysis.
---

## Interactive and Feedback System in Simulation

> #### Interactive Systems
- Interactive Systems are the computer systems characterized by significant amount of interaction between humans and the computer. Macintosh and Windows computer operating systems are prime examples of graphical interactive systems.

- Editors, CAD-CAM(Computer Aided Design - Computer Aided Manufacture) system, and data entry systems are all computer systems involving a high degree of human - computer interaction. Games and simulations are interactive systems. Web browsers and integrated development environments (IDE) are also examples of very complex interactive systems.

> #### Feedback Systems
- The system takes feedback from the output i.e input is coupled with output. A significant factor in the performance of many systems is that coupling occurs between the input and output of the system. The term feedback is used to describe the phenomenon.  
- The example of feedback system in which there is continuous controlling the aircraft system.

    ```mermaid
    graph LR
        G(Gyroscope)
        C(Control Surface)
        A(Air Frames)
        
        G-->|"ε"|C-->A-->G
    ```

- Here, the input is the **desired aircraft heading**, and the output is the **actual heading**. The gyroscope of the autopilot detects the difference between the two headings.

- A **feedback loop** is established by using this difference to operate the control surface. Since the change in heading affects the signal used to control the heading, the difference between the desired signal $Q_t$ and the actual heading $Q_0$ is called the **error signal**.  

Since it measures the extent to which the system deviates from the desired condition, it is denoted by 
𝜖.

$$
\epsilon = Q_t - Q_0...........................\text{(i)}
$$

The torque acting on the system is given by:

$$
\text{Torque} = K\epsilon - D Q_0'...........................\text{(ii)}
$$

Since we also know that torque is related to angular acceleration as:

$$
\text{Torque} = I Q_0''...........................\text{(iii)}
$$

From equations (1), (2), and (3), we obtain:

$$
I Q_0'' + D Q_0' + K Q_0 = K Q_t \quad .................\text{(iv)}
$$


$$Torque = K\epsilon - DQ_0'$$
$$IQ_0'' = K(Q_t - Q_0) - DQ_0'$$
$$IQ_0'' = KQ_t-KQ_0-DQ_0'$$
$$IQ_0''+DQ_0+KQ_0 = KQ_t$$



Dividing both sides by \( I \) and making the following substitutions:

$$
2E\omega = \frac{D}{I}, \quad \omega^2 = \frac{K}{I}
$$

We rewrite Equation (4) as:

$$
Q_0'' + \frac{D}{I} Q_0' + \frac{K}{I} Q_0 = \frac{K}{I} Q_t
$$

Substituting the defined parameters:

$$
Q_0'' + 2E\omega Q_0' + \omega^2 Q_0 = \omega^2 Q_t \quad ................\text{(v)}
$$

where \( E \) is the **damping factor**.

This is a ***second-order differential equation*** describing the system's response.

---


> ### Q. Explain how do you update the clock time in system simulation.
> ### Clock time in System Simulation
- CLock time is updated based on the following two models. 

        - Fixed Time Step Model
        - Event to EVent Model

> Fixed time step model:
- In this, the timer simulated by the computer is updated at a fixed time interval. The system is checked to see if any event has taken place during that interval. All the events which takes place during the time interval are considered to have occurred simultaneously at the end of the interval.

> Event-to-Event Model:
- It is also known as the next event model. In this the computer advances the time to the occurrence of the next event. So it shifts from one event to the another event and the system state does not change in between. A track of the current time is kept when something interesting happens to the system.  