----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 20.12.2018 08:53:25
-- Design Name: 
-- Module Name: afficheur_global - Behavioral
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

entity afficheur_global is
    Port ( 
--           unite2 : in STD_LOGIC_VECTOR (4 downto 0);
--           unite : in STD_LOGIC_VECTOR (4 downto 0);
--           dizaine : in STD_LOGIC_VECTOR (4 downto 0);
--           centaine : in STD_LOGIC_VECTOR (4 downto 0);
--           millier : in STD_LOGIC_VECTOR (4 downto 0);
--           milliers2 : in STD_LOGIC_VECTOR(4 downto 0);
--           milliers3 : in STD_LOGIC_VECTOR(4 downto 0);
--           milliers4 : in STD_LOGIC_VECTOR(4 downto 0);
           data_1 : in STD_LOGIC_VECTOR(19 downto 0);
           data_2 : in STD_LOGIC_VECTOR(19 downto 0);
           
           dp_vecteur : in STD_LOGIC_VECTOR (7 downto 0);
           rst : in STD_LOGIC;
           clk : in STD_LOGIC;
           abcdefg : out STD_LOGIC_VECTOR (6 downto 0);
           dp : out STD_LOGIC;
           AN : out STD_LOGIC_VECTOR (7 downto 0));
end afficheur_global;

architecture Behavioral of afficheur_global is



component generateur
    Port ( g_rst : in STD_LOGIC;
           g_clk : in STD_LOGIC;
           g_AN : out STD_LOGIC_VECTOR (7 downto 0));
end component;

component afficheur
Port ( 
--           dp : in STD_LOGIC;
           valeur : in STD_LOGIC_VECTOR(4 downto 0);
           abcdefg : out std_logic_vector(6 downto 0);
           dp_in : in std_logic;
           dp_out :out std_logic
       );
end component;

component aiguilleur
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
       AN : in STD_LOGIC_VECTOR (7 downto 0);
       valeur : out STD_LOGIC_VECTOR (4 downto 0);
       dp : out STD_LOGIC
       );
end component;

signal s_AN:STD_LOGIC_VECTOR(7 downto 0);
signal s_valeur:STD_LOGIC_VECTOR(4 downto 0);
signal s_dp:STD_LOGIC;

signal s_unite2 : STD_LOGIC_VECTOR (4 downto 0);
signal s_unite : STD_LOGIC_VECTOR (4 downto 0);
signal s_dizaine : STD_LOGIC_VECTOR (4 downto 0);
signal s_centaine : STD_LOGIC_VECTOR (4 downto 0);
signal s_millier :  STD_LOGIC_VECTOR (4 downto 0);
signal s_milliers2 : STD_LOGIC_VECTOR(4 downto 0);
signal s_milliers3 :  STD_LOGIC_VECTOR(4 downto 0);
signal s_milliers4 :  STD_LOGIC_VECTOR(4 downto 0);

begin

AN <= s_AN;

s_unite2 <= data_1(4 downto 0);
s_unite <= data_1(9 downto 5);
s_dizaine <= data_1(14 downto 10);
s_centaine <= data_1(19 downto 15);

s_millier <= data_2(4 downto 0);
s_milliers2 <= data_2(9 downto 5);
s_milliers3 <= data_2(14 downto 10);
s_milliers4 <= data_2(19 downto 15);

A:aiguilleur
    port map(
           unite2 => s_unite2,
           unite => s_unite,
           dizaine => s_dizaine,
           centaine => s_centaine,
           millier => s_millier,
           milliers2 => s_milliers2,
           milliers3 => s_milliers3,
           milliers4 => s_milliers4,
           
           dp_vect => dp_vecteur,
           AN => s_AN,
           valeur => s_valeur,
           dp => s_dp
           );

B:generateur
    port map(
           g_rst => rst,
           g_clk => clk,
           g_AN => s_AN);

C:afficheur
    port map( 
       dp_in => s_dp,
       dp_out => dp,
       valeur => s_valeur,
       abcdefg => abcdefg);
end Behavioral;
