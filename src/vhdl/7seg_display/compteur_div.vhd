----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 04.12.2018 16:13:50
-- Design Name: 
-- Module Name: generateur - Behavioral
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

entity compteur_div is
    Port ( rst : in STD_LOGIC;
           H_1k,clk : in STD_LOGIC;
           AN : out STD_LOGIC_VECTOR (7 downto 0));
end compteur_div;

architecture Behavioral of compteur_div is

signal s_AN : STD_LOGIC_VECTOR (7 downto 0);

begin



process (clk, rst, s_AN)
begin
    if rst = '1' then
        s_AN <= "11111110";
        AN <= s_AN;
    elsif rising_edge(clk) then
        if H_1k = '1' then
        case s_AN is
            when "11111110" => 
                AN <= "11111101";
                s_AN <= "11111101";
            when "11111101" => 
                AN <= "11111011";
                s_AN <= "11111011";
            when "11111011" => 
                AN <= "11110111";
                s_AN <= "11110111";
            when "11110111" => 
                AN <= "11101111";
                s_AN <= "11101111";
            when "11101111" => 
                AN <= "11011111";
                s_AN <= "11011111";
            when "11011111" => 
                AN <= "10111111";
                s_AN <= "10111111";
            when "10111111" => 
                AN <= "01111111";
                s_AN <= "01111111";
            when "01111111" => 
                AN <= "11111110";
                s_AN <= "11111110";
            when others => 
                AN <= "11111110";
                s_AN <= "11111110";
            end case;
        end if;
    end if;
end process;
end Behavioral;
