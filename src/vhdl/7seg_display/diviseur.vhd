----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 04.12.2018 15:55:55
-- Design Name: 
-- Module Name: diviseur - Behavioral
-- Project Name: 
-- Target Devices: 
-- Tool Versions: 
-- Description: 
-- 
-- Dependencies: 
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity diviseur is
    Port ( rst : in STD_LOGIC;
           clk : in STD_LOGIC;
           H_1k : out STD_LOGIC);
end diviseur;

architecture Behavioral of diviseur is

signal cpt : INTEGER RANGE 0 to 50000;

begin
process (clk, rst)
begin
--100 MhZ
    if rst = '1' then
        H_1k <= '0';
        cpt <= 0;
    elsif rising_edge(clk) then
        if cpt = 50000 then
            H_1k <= '1'; 
            cpt <= 0;
        else
            H_1k <= '0'; 
            cpt <= cpt + 1;

        end if;
    end if;
end process;

end Behavioral;
