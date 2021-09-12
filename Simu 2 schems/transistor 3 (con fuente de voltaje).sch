<Qucs Schematic 0.0.20>
<Properties>
  <View=0,0,993,800,1,0,0>
  <Grid=10,10,1>
  <DataSet=transistor 3 (con fuente de voltaje).dat>
  <DataDisplay=transistor 3 (con fuente de voltaje).dpl>
  <OpenDisplay=1>
  <Script=transistor 3 (con fuente de voltaje).m>
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
  <.DC DC1 1 60 160 0 37 0 0 "26.85" 0 "0.001" 0 "1 pA" 0 "1 uV" 0 "no" 0 "150" 0 "no" 0 "none" 0 "CroutLU" 0>
  <Vdc V1 1 390 190 18 -26 0 1 "vcc" 1>
  <Vdc V2 1 470 320 18 -26 0 1 "v2cc" 1>
  <GND *1 5 430 420 0 0 0 0>
  <.SW SW1 1 60 240 0 59 0 0 "DC1" 1 "lin" 1 "vcc" 1 "0" 1 "12" 1 "13" 1>
  <.SW SW2 1 220 240 0 59 0 0 "SW1" 1 "lin" 1 "v2cc" 1 "0" 1 "12" 1 "13" 1>
  <_BJT T_2N2222_1 1 770 300 12 -32 0 0 "npn" 0 "1e-14" 0 "1" 0 "1" 0 "0.3" 0 "0" 0 "100" 0 "0" 0 "0" 0 "1.5" 0 "0" 0 "2" 0 "200" 0 "3" 0 "0" 0 "0" 0 "3" 0 "1" 0 "10" 0 "25e-12" 0 "0.75" 0 "0.33" 0 "8e-12" 0 "0.75" 0 "0.33" 0 "1.0" 0 "0" 0 "0.75" 0 "0" 0 "0.5" 0 "400e-12" 0 "3" 0 "0.0" 0 "2" 0 "100e-9" 0 "26.85" 0 "0.0" 0 "1.0" 0 "1.0" 0 "0.0" 0 "1.0" 0 "1.0" 0 "0.0" 0 "0.0" 0 "3.0" 0 "1.11" 0 "26.85" 0 "1.0" 0>
  <IProbe Pr1 1 770 220 -41 -26 0 3>
  <VProbe Pr2 1 900 150 28 -31 0 0>
  <IProbe Pr3 1 690 220 -41 -26 0 3>
  <R R3 1 770 370 15 -26 0 1 "1k Ohm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "US" 0>
  <R R1 1 770 130 15 -26 0 1 "10k Ohm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "US" 0>
  <R R2 1 470 240 15 -26 0 1 "40k Ohm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "US" 0>
  <R R4 1 590 320 15 -26 0 1 "4k Ohm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "US" 0>
</Components>
<Wires>
  <470 270 470 290 "" 0 0 0 "">
  <390 220 390 420 "" 0 0 0 "">
  <470 350 470 420 "" 0 0 0 "">
  <430 420 470 420 "" 0 0 0 "">
  <390 420 430 420 "" 0 0 0 "">
  <470 420 590 420 "" 0 0 0 "">
  <470 160 470 210 "" 0 0 0 "">
  <470 160 590 160 "" 0 0 0 "">
  <390 100 390 160 "" 0 0 0 "">
  <390 100 770 100 "" 0 0 0 "">
  <770 250 770 270 "" 0 0 0 "">
  <770 160 770 180 "" 0 0 0 "">
  <770 180 770 190 "" 0 0 0 "">
  <770 180 890 180 "" 0 0 0 "">
  <890 170 890 180 "" 0 0 0 "">
  <690 160 690 190 "" 0 0 0 "">
  <690 250 690 300 "" 0 0 0 "">
  <690 300 740 300 "" 0 0 0 "">
  <770 330 770 340 "" 0 0 0 "">
  <910 170 910 420 "" 0 0 0 "">
  <770 400 770 420 "" 0 0 0 "">
  <770 420 910 420 "" 0 0 0 "">
  <590 160 690 160 "" 0 0 0 "">
  <590 160 590 290 "" 0 0 0 "">
  <590 420 770 420 "" 0 0 0 "">
  <590 350 590 420 "" 0 0 0 "">
</Wires>
<Diagrams>
</Diagrams>
<Paintings>
</Paintings>
