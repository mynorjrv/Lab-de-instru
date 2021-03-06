<Qucs Schematic 0.0.20>
<Properties>
  <View=0,0,953,800,1,0,0>
  <Grid=10,10,1>
  <DataSet=experimentos.dat>
  <DataDisplay=experimentos.dpl>
  <OpenDisplay=1>
  <Script=experimentos.m>
  <RunScript=0>
  <showFrame=0>
  <FrameText0=Title>
  <FrameText1=Drawn By:>
  <FrameText2=Date:>
  <FrameText3=Revision:>
</Properties>
<Symbol>
</Symbol>
<Components>
  <.DC DC1 1 100 170 0 37 0 0 "26.85" 0 "0.001" 0 "1 pA" 0 "1 uV" 0 "no" 0 "150" 0 "no" 0 "none" 0 "CroutLU" 0>
  <.SW SW1 1 100 250 0 59 0 0 "DC1" 1 "lin" 1 "vcc" 1 "0" 1 "12" 1 "10001" 1>
  <.SW SW2 1 260 250 0 59 0 0 "SW1" 1 "lin" 1 "icc" 1 "0" 1 "60 u" 1 "11" 1>
  <GND *1 5 500 390 0 0 0 0>
  <_BJT T_2N2222_1 1 700 340 12 -32 0 0 "npn" 0 "1e-14" 0 "1" 0 "1" 0 "0.3" 0 "0" 0 "100" 0 "0" 0 "0" 0 "1.5" 0 "0" 0 "2" 0 "200" 0 "3" 0 "0" 0 "0" 0 "3" 0 "1" 0 "10" 0 "25e-12" 0 "0.75" 0 "0.33" 0 "8e-12" 0 "0.75" 0 "0.33" 0 "1.0" 0 "0" 0 "0.75" 0 "0" 0 "0.5" 0 "400e-12" 0 "3" 0 "0.0" 0 "2" 0 "100e-9" 0 "26.85" 0 "0.0" 0 "1.0" 0 "1.0" 0 "0.0" 0 "1.0" 0 "1.0" 0 "0.0" 0 "0.0" 0 "3.0" 0 "1.11" 0 "26.85" 0 "1.0" 0>
  <IProbe Pr1 1 700 260 -41 -26 0 3>
  <R R1 1 700 170 15 -26 0 1 "2k Ohm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "US" 0>
  <VProbe Pr2 1 830 190 28 -31 0 0>
  <IProbe Pr3 1 600 320 -26 16 0 0>
  <Idc I1 1 500 360 18 -26 0 1 "icc" 1>
  <Vdc V1 1 460 230 18 -26 0 1 "vcc" 1>
</Components>
<Wires>
  <500 390 700 390 "" 0 0 0 "">
  <700 370 700 390 "" 0 0 0 "">
  <700 130 700 140 "" 0 0 0 "">
  <700 290 700 310 "" 0 0 0 "">
  <700 390 840 390 "" 0 0 0 "">
  <840 210 840 390 "" 0 0 0 "">
  <700 200 700 220 "" 0 0 0 "">
  <700 220 700 230 "" 0 0 0 "">
  <700 220 820 220 "" 0 0 0 "">
  <820 210 820 220 "" 0 0 0 "">
  <460 390 500 390 "" 0 0 0 "">
  <460 260 460 390 "" 0 0 0 "">
  <460 130 700 130 "" 0 0 0 "">
  <460 130 460 200 "" 0 0 0 "">
  <630 320 630 340 "" 0 0 0 "">
  <630 340 670 340 "" 0 0 0 "">
  <500 320 500 330 "" 0 0 0 "">
  <500 320 570 320 "" 0 0 0 "">
</Wires>
<Diagrams>
</Diagrams>
<Paintings>
</Paintings>
