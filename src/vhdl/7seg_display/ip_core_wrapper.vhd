--Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
----------------------------------------------------------------------------------
--Tool Version: Vivado v.2018.2 (win64) Build 2258646 Thu Jun 14 20:03:12 MDT 2018
--Date        : Thu Jan 23 20:29:27 2020
--Host        : n7-b303-05 running 64-bit major release  (build 9200)
--Command     : generate_target ip_core_wrapper.bd
--Design      : ip_core_wrapper
--Purpose     : IP block netlist
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
library UNISIM;
use UNISIM.VCOMPONENTS.ALL;
entity ip_core_wrapper is
  port (
    AN_out : out STD_LOGIC_VECTOR ( 7 downto 0 );
    DP_out : out STD_LOGIC;
    MISO : in STD_LOGIC;
    MOSI : out STD_LOGIC;
    SCLK : out STD_LOGIC;
    SS : out STD_LOGIC;
    VGA_B : out STD_LOGIC_VECTOR ( 3 downto 0 );
    VGA_G : out STD_LOGIC_VECTOR ( 3 downto 0 );
    VGA_HS : out STD_LOGIC;
    VGA_R : out STD_LOGIC_VECTOR ( 3 downto 0 );
    VGA_VS : out STD_LOGIC;
    clk_100MHz : in STD_LOGIC;
    reset_rtl_0 : in STD_LOGIC;
    seg7_out : out STD_LOGIC_VECTOR ( 6 downto 0 );
    switchs : in STD_LOGIC_VECTOR ( 15 downto 0 );
    uart_rtl_0_rxd : in STD_LOGIC;
    uart_rtl_0_txd : out STD_LOGIC
  );
end ip_core_wrapper;

architecture STRUCTURE of ip_core_wrapper is
  component ip_core is
  port (
    uart_rtl_0_rxd : in STD_LOGIC;
    uart_rtl_0_txd : out STD_LOGIC;
    reset_rtl_0 : in STD_LOGIC;
    clk_100MHz : in STD_LOGIC;
    seg7_out : out STD_LOGIC_VECTOR ( 6 downto 0 );
    AN_out : out STD_LOGIC_VECTOR ( 7 downto 0 );
    DP_out : out STD_LOGIC;
    MISO : in STD_LOGIC;
    MOSI : out STD_LOGIC;
    SS : out STD_LOGIC;
    SCLK : out STD_LOGIC;
    switchs : in STD_LOGIC_VECTOR ( 15 downto 0 );
    VGA_HS : out STD_LOGIC;
    VGA_VS : out STD_LOGIC;
    VGA_R : out STD_LOGIC_VECTOR ( 3 downto 0 );
    VGA_B : out STD_LOGIC_VECTOR ( 3 downto 0 );
    VGA_G : out STD_LOGIC_VECTOR ( 3 downto 0 )
  );
  end component ip_core;
begin
ip_core_i: component ip_core
     port map (
      AN_out(7 downto 0) => AN_out(7 downto 0),
      DP_out => DP_out,
      MISO => MISO,
      MOSI => MOSI,
      SCLK => SCLK,
      SS => SS,
      VGA_B(3 downto 0) => VGA_B(3 downto 0),
      VGA_G(3 downto 0) => VGA_G(3 downto 0),
      VGA_HS => VGA_HS,
      VGA_R(3 downto 0) => VGA_R(3 downto 0),
      VGA_VS => VGA_VS,
      clk_100MHz => clk_100MHz,
      reset_rtl_0 => reset_rtl_0,
      seg7_out(6 downto 0) => seg7_out(6 downto 0),
      switchs(15 downto 0) => switchs(15 downto 0),
      uart_rtl_0_rxd => uart_rtl_0_rxd,
      uart_rtl_0_txd => uart_rtl_0_txd
    );
end STRUCTURE;
