# SYSTEM DESIGN - EMBEDDED SYSTEMS
[Source - MHRD youtube](https://www.youtube.com/watch?v=cZKBTCbkXoo) <br />
[Source - Engineering Funda](https://www.youtube.com/watch?v=C9sIFWwJETs)

## Approachs:
1. top-down: Abstract idea to components
2. bottom-up: components to higher level system. 
*Mostly this considered becuase abstract design is not concrete.*

## Flow:
1. Analyse design at each stage.
2. Refine.
3. Verify and test.

## Steps involved:
1. Requirements, Abstraction, Problem Statement
2. Architecture
3. Components
4. System integration

### 1. Requirements, Abstraction, Problem Statement
* Functional 
    * Inputs, Outputs
    * Functions / Features
* Non-Functional
Goals:
    1. Cost
    2. Performance
    3. Power Consumption
    4. Size/Weight

Minimal effort, resources, and features based on requirement that solves the requirement.

### 2. Architecture Design
* Implmentation of the system is the architecture. 
* Highlights major parts and flow of features in the system.
* C4 block diagram for example to satisfy all functional requirements.
#### Sub-systems (work in different teams).
* **Hardware** - processor, I/O, memory, sensors etc. (Electrical Schematics going deeper)
* **Software** - Software flow. Input to Output. Process knowledge.
    * check for available designs in the market.
    * check UI requirement.

### 3. Components (Modular Design)
* Depending upon the speed and deadlines, we would need powerful processes and therefore might go for costlier solution. 
* If we have a budget constraint and are restricted to procure high performance hardware, software has to be designed to accomodate it. <br />
* **Goals** (performance, power, cost) govern the hardware/software module selection.
So the component selection is interdependent.

### 4. System Integration
* Determine and implement the flow between modules. (Mapping)
* Unit tested hardware and software components by now.
* The software modules should be integrated to see functionality on test bench.
* This is then deployed on hardware with real peripherals and memory constraints.










