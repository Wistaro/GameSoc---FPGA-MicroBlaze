----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 04.12.2018 11:03:33
-- Design Name: 
-- Module Name: afficheur - Behavioral
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

entity afficheur is
    Port ( 
--           dp : in STD_LOGIC;
           valeur : in STD_LOGIC_VECTOR(4 downto 0);
           abcdefg : out std_logic_vector(6 downto 0);
           dp_in : in std_logic;
           dp_out :out std_logic
       );
end afficheur;

architecture Behavioral of afficheur is

begin

abcdefg <= "0000001" when valeur = "00000" else -- 0 ou O
           "1001111" when valeur = "00001" else --1
            "0010010" when valeur = "00010" else --2
            "0000110" when valeur = "00011" else -- 3
            "1001100" when valeur = "00100" else -- 4
            "0100100" when valeur = "00101" else -- 5 ou S
            "0100000" when valeur = "00110" else -- 6
            "0001111" when valeur = "00111" else -- 7
            "0000000" when valeur = "01000" else -- 8
            "0000100" when valeur = "01001" else -- 9
            "0110001" when valeur = "01100" else -- C = 12
            "0111000" when valeur = "01111" else -- F = 15
            "1111110" when valeur = "01101" else -- - = 13
            
            
             "0001000" when valeur = "01010" else -- A = 10
             "0011001" when valeur = "01011" else -- R = 11
             "1110000" when valeur = "01110" else -- T = 14
             "1110001" when valeur = "10000" else -- L = 16
             "0001001" when valeur = "10001" else -- N = 17
             "1101000" when valeur = "10010" else -- H = 18
             "1100001" when valeur = "10011" else -- G = 19
             "1100000" when valeur = "10100" else -- B = 20
             "0011000" when valeur = "10101" else -- P = 21
             "1000001" when valeur = "10110" else -- U = 22
             "0110000" when valeur = "10111" else -- E = 23
             "1111001" when valeur = "11000" else -- I = 24
             "1000010" when valeur = "11001" else -- D = 25
             "1000011" when valeur = "11010" else -- J = 26
             "0101000" when valeur = "11011" else -- K = 27
             "0101011" when valeur = "11100" else -- M = 28
             "1110111" when valeur = "11101" else -- _ = 29
             "0011010" when valeur = "11110" else -- ? = 30
            
             "1111111";
            

-- Gestion erreur
            
--            "1111111" when valeur = "1010" else
--            "1111111" when valeur = "1011" else
--            "1111111" when valeur = "1100" else
--            "1111111" when valeur = "1101" else
--            "1111111" when valeur = "1110" 
--            else
--            "1111111" when valeur = "1111";
dp_out <= dp_in;

end Behavioral;
