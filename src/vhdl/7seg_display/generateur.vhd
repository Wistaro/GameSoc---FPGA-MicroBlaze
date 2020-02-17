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

entity generateur is
    Port ( g_rst : in STD_LOGIC;
           g_clk : in STD_LOGIC;
           g_AN : out STD_LOGIC_VECTOR (7 downto 0));
end generateur;

architecture Behavioral of generateur is

signal H_1k : STD_LOGIC;

component compteur_div 
    Port ( rst : in STD_LOGIC;
       H_1k,clk : in STD_LOGIC;
       AN : out STD_LOGIC_VECTOR (7 downto 0));
end component;

component diviseur
    Port ( rst : in STD_LOGIC;
       clk : in STD_LOGIC;
       H_1k : out STD_LOGIC);
end component;


begin

A:compteur_div
    port map(
        rst=>g_rst,
        clk=>g_clk,
        H_1k=>H_1k,
        AN=>g_AN);
        
B:diviseur
    port map(
        rst => g_rst,
        clk => g_clk,
        H_1k => H_1k);
        
end Behavioral;
