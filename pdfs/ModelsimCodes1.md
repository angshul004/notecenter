# VHDL Code for Logic Gates and Arithmetic Circuits

## AND Gate
```vhdl
library IEEE;
use IEEE.std_logic_1164.all;

entity andGate is
    Port(A: in std_logic;
       B: in std_logic;
       Y: out std_logic);
end andGate;

architecture andLogic of andGate is
begin
    Y <= A AND B;
end andLogic;
```

## OR Gate
```vhdl
library IEEE;
use IEEE.std_logic_1164.all;

entity orGate is
    Port(A: in std_logic;
       B: in std_logic;
       Y: out std_logic);
end orGate;

architecture orLogic of orGate is
begin
    Y <= A OR B;
end orLogic;
```

## NOT Gate
```vhdl
library IEEE;
use IEEE.std_logic_1164.all;

entity notGate is
    port(A: in std_logic;
       Y: out std_logic);
end notGate;

architecture notLogic of notGate is
begin
    Y <= NOT(A);
end notLogic;
```

## NAND Gate
```vhdl
library IEEE;
use IEEE.std_logic_1164.all;

entity nandGate is
    port(A: in std_logic;
    B: in std_logic;
    Y: out std_logic);
end nandGate;

architecture nandLogic of nandGate is
begin
    Y <= NOT(A AND B);
end nandLogic;
```

## NOR Gate
```vhdl
library IEEE;
use IEEE.std_logic_1164.all;

entity norGate is
    port(A: in std_logic;
    B: in std_logic;
    Y: out std_logic);
end norGate;

architecture norLogic of norGate is
begin
    Y <= NOT(A OR B);
end norLogic;
```

## XOR Gate
```vhdl
library IEEE;
use IEEE.std_logic_1164.all;

entity xorGate is
    port(A: in std_logic;
    B: in std_logic;
    Y: out std_logic);
end xorGate;

architecture xorLogic of xorGate is
begin
    Y <= (A XOR B);
end xorLogic;
```

## XNOR Gate
```vhdl
library IEEE;
use IEEE.std_logic_1164.all;

entity xnorGate is
    port(A: in std_logic;
    B: in std_logic;
    Y: out std_logic);
end xnorGate;

architecture xnorLogic of xnorGate is
begin
    Y <= (A XNOR B);
end xnorLogic;
```

## Half Adder
```vhdl
library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_ARITH.all;
use IEEE.std_logic_UNSIGNED.all;

entity halfAdder is
    port(a, b: in bit;
    sum, carry: out bit);
end halfAdder;

architecture data of halfAdder is
begin
    sum <= a XOR b;
    carry <= a AND b;
end data;
```

## Full Adder
```vhdl
library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_ARITH.all;
use IEEE.std_logic_UNSIGNED.all;

entity fullAdder is
    port(a, b, c: in bit;
    sum, carry: out bit);
end fullAdder;

architecture data of fullAdder is
begin
    sum <= a XOR b XOR c;
    carry <= ((a AND b) OR (b AND c) OR (a AND c));
end data;
```

## Half Subtractor
```vhdl
library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_ARITH.all;
use IEEE.std_logic_UNSIGNED.all;

entity halfSub is
    port(a, b: in bit;
    dif, bo: out bit);
end halfSub;

architecture data of halfSub is
begin
    dif <= a XOR b;
    bo <= (NOT(a)) AND b;
end data;
```

## Full Subtractor
```vhdl
library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_ARITH.all;
use IEEE.std_logic_UNSIGNED.all;

entity fullSub is
    port(a, b, bin: in bit;
    dif, bout: out bit);
end fullSub;

architecture data of fullSub is
begin
    dif <= a XOR b XOR bin;
    bout <= (NOT(a) AND bin) OR (NOT(a) AND b) OR (b AND bin);
end data;
```

## Multiplexer (MUX)
```vhdl
library IEEE;
use IEEE.std_logic_1164.all;

entity mux is
    port(
        a, b, c, d : in std_logic;
        s0, s1 : in std_logic;
        z : out std_logic
    );
end mux;

architecture behave of mux is
begin
    process(a, b, c, d, s0, s1)
    begin
        if (s0 = '0' and s1 = '0') then
            z <= a;
        elsif (s0 = '0' and s1 = '1') then
            z <= b;
        elsif (s0 = '1' and s1 = '0') then
            z <= c;
        elsif (s0 = '1' and s1 = '1') then
            z <= d;
        end if;
    end process;
end behave;
```

## Demultiplexer (DEMUX)
```vhdl
library IEEE;
use IEEE.std_logic_1164.all;

entity demux is
    port (
        a  : in  std_logic;
        s  : in  std_logic_vector(1 downto 0);
        m  : out std_logic_vector(3 downto 0)
    );
end demux;

architecture arc of demux is
begin
    process (a, s)
    begin
        m <= "0000";
        if (s = "00") then
            m(0) <= a;
        elsif (s = "01") then
            m(1) <= a;
        elsif (s = "10") then
            m(2) <= a;
        elsif (s = "11") then
            m(3) <= a;
        else
            m <= "ZZZZ";
        end if;
    end process;
end arc;
