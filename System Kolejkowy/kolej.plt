set title "System kolejkowy";
set xrange [0:7];
set yrange [0:6];
set linestyle 1 lc rgb '#0060ad' lt 1 lw 2 pt 7 ps 1.5;   # --- blue
set linestyle 2 lc rgb '#dd181f' lt 1 lw 2 pt 5 ps 1.5;   # --- red
set linestyle 3 lc rgb '#66FF33' lt 1 lw 2 pt 5 ps 1.5;   # --- green

plot  'stanKanalow.dat' with lines ls 3 title "stan zajetych kanalow";
replot  'odrzucone.dat' with lines ls 2 title "odrzucone w jednostce czasu";
replot 'czasPrzybycia.dat' with points pt 9 ps 1.5 title "wejscie";
replot 'czasObslugi.dat' with points pt 11 ps 1.5 title "obsluga zgloszenia";
replot 'czasZakonczeniaObslugi.dat' with points pt 3 ps 1.5 title "zakończenie obslugi";
exit;