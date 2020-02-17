----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 04.12.2018 15:08:31
-- Design Name: 
-- Module Name: aiguilleur - Behavioral
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

entity aiguilleur is
    Port ( 
           unite2: in std_logic_vector(4 downto 0);
           unite : in STD_LOGIC_VECTOR (4 downto 0);
           dizaine : in STD_LOGIC_VECTOR (4 downto 0);
           centaine : in STD_LOGIC_VECTOR (4 downto 0);
           millier : in STD_LOGIC_VECTOR (4 downto 0);
           milliers2 : in STD_LOGIC_VECTOR(4 downto 0);
           milliers3 : in STD_LOGIC_VECTOR(4 downto 0);
           milliers4 : in STD_LOGIC_VECTOR(4 downto 0);
           
           dp_vect : in STD_LOGIC_VECTOR (7 downto 0);
           --AN : in STD_LOGIC_VECTOR (4 downto 0);
           AN : in STD_LOGIC_VECTOR (7 downto 0);
           valeur : out STD_LOGIC_VECTOR (4 downto 0);
           dp : out STD_LOGIC
           );
end aiguilleur;

architecture Behavioral of aiguilleur is

begin

process(AN,unite2,unite,dizaine,centaine,millier,dp_vect)
begin
    case AN is
        when "11111110" =>
            valeur <= unite2;
            dp <= dp_vect(0);
        when "11111101" =>
            valeur <= unite;
            dp <= dp_vect(1);
        when "11111011" =>
            valeur <= dizaine;
            dp <= dp_vect(2);
        when "11110111" =>
            valeur <= centaine;
            dp <= dp_vect(3);
        when "11101111" =>
            valeur <= millier;
            dp <= dp_vect(4);
         when "11011111" =>
            valeur <= milliers2;
            dp <= dp_vect(5);   
         when "10111111" =>
            valeur <= milliers3;
            dp <= dp_vect(6); 
         when "01111111" =>
            valeur <= milliers4;
            dp <= dp_vect(7);            
        when others =>
            valeur <= "00000";
            dp <= '1';
        end case;
end process;

end Behavioral;
