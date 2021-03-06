<Qucs Schematic 0.0.20>
<Properties>
  <View=0,41,990,680,1,0,0>
  <Grid=10,10,1>
  <DataSet=El del diodo.dat>
  <DataDisplay=El del diodo.dpl>
  <OpenDisplay=1>
  <Script=El del diodo.m>
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
  <Diode D1 1 240 250 15 -26 0 1 "1e-15 A" 1 "1" 1 "10 fF" 1 "0.5" 0 "0.7 V" 0 "0.5" 0 "0.0 fF" 0 "0.0" 0 "2.0" 0 "0.0 Ohm" 0 "0.0 ps" 0 "0" 0 "0.0" 0 "1.0" 0 "1.0" 0 "0" 0 "1 mA" 0 "26.85" 0 "3.0" 0 "1.11" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0" 0 "26.85" 0 "1.0" 0 "normal" 0>
  <IProbe Pr1 1 150 340 -26 16 1 2>
  <R R1 1 150 160 -26 15 0 0 "100 Ohm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "US" 0>
  <GND * 5 60 340 0 0 0 0>
  <Vdc V1 1 60 250 18 -26 0 1 "vin" 1>
  <IProbe Pr2 1 490 340 -26 16 1 2>
  <R R2 1 490 160 -26 15 0 0 "100 Ohm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "US" 0>
  <GND *1 5 400 340 0 0 0 0>
  <Vdc V2 1 400 250 18 -26 0 1 "vin" 1>
  <.DC DC1 1 70 70 0 37 0 0 "26.85" 0 "0.001" 0 "1 pA" 0 "1 uV" 0 "no" 0 "150" 0 "no" 0 "none" 0 "CroutLU" 0>
  <Lib D2 1 580 250 13 6 0 1 "Z-Diodes" 0 "1N4734A" 1>
  <.SW SW1 1 780 150 0 59 0 0 "DC1" 1 "lin" 1 "vin" 1 "0" 1 "6" 1 "1001" 1>
</Components>
<Wires>
  <180 160 240 160 "" 0 0 0 "">
  <240 160 240 220 "" 0 0 0 "">
  <240 280 240 340 "" 0 0 0 "">
  <180 340 240 340 "" 0 0 0 "">
  <60 340 120 340 "" 0 0 0 "">
  <60 280 60 340 "" 0 0 0 "">
  <60 160 120 160 "" 0 0 0 "">
  <60 160 60 220 "" 0 0 0 "">
  <400 340 460 340 "" 0 0 0 "">
  <400 280 400 340 "" 0 0 0 "">
  <400 160 460 160 "" 0 0 0 "">
  <400 160 400 220 "" 0 0 0 "">
  <520 160 580 160 "" 0 0 0 "">
  <580 160 580 220 "" 0 0 0 "">
  <520 340 580 340 "" 0 0 0 "">
  <580 280 580 340 "" 0 0 0 "">
  <240 160 240 160 "Vo1" 270 130 0 "">
  <580 160 580 160 "Vo2" 610 130 0 "">
</Wires>
<Diagrams>
</Diagrams>
<Paintings>
</Paintings>
