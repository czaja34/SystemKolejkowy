set title "System kolejkowy";
set xrange [0:7];
set yrange [0:6];
set linestyle 1 lc rgb '#0060ad' lt 1 lw 2 pt 7 ps 1.5;   # --- blue
plot 'stanKolejki.dat' with lines ls 1 title "Stan kolejki";
replot 'czasPrzybycia.dat' with points pt 9 ps 1.5 title "wejscie";
replot 'czasObslugi.dat' with points pt 11 ps 1.5 title "obsluga zgloszenia";
replot 'czasZakonczeniaObslugi.dat' with points pt 3 ps 1.5 title "zakończenie obslugi";
exit;