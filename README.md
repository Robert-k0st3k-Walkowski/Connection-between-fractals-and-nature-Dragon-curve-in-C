# Temat: Eksploracja połączeń między fraktalami, a naturą przy pomocy "Krzywej Smoka"

Myślę, że niektórzy odbiorcy mojego projektu mogą nie wiedzieć, co to jest fraktal w ogóle, więc przedstawię krótką jego definicję:

- **Fraktal** <- oznacza zwykle obiekt samopodobny (obiekt jest samopodobny, jeżeli jego pewne elementy są podobne do całości) albo "nieskończenie złożony, czyli ukazujący coraz większe detale. Ze względu na ich różnorodność, unika się podawania jakiejkolwiek ścisłej definicji, a obiekt można nazwać fraktalem, jeżeli spełnia wszystkie lub większość tych cech:
    - Ma skomplikowaną strukturę w każdej skali
    - Struktura ta nie jest łatwa do opisania w jeżyku tradycyjnej geometrii euklidesowej,
    - Jest samopodobny, jeżeli nie dosłownie, to w wersji przybliżonej lub stochastycznej,
    - Ma względnie prostą definicję rekurencyjną,
    - Ma naturalny ("poszarpany", "kłębiasty" itp.) wygląd.

To delikatnie skrócona wersja definicji fraktala, ale dzięki niej możemy już przejść do definicji krzywej smoka:

- **Krzywa smoka** <- jest to członek rodziny samopodobnych krzywych fraktalnych, które można „aprokysmować” (inaczej oszacować) za pomocą metody rekursyjnych takich jak system Lindenmayera. Krzywą smoka najczęściej uważano prawdopodobnie za krzstałt, który jest generowany poprzez powtarzalne składanie paska papieru na pół.

![krzywa_smoka](https://github.com/IS-UMK/2024-js-project-Robert-k0st3k-Walkowski/assets/147077004/9822f16e-6a3e-44a5-bf18-dd32af5ec50b) ![Dragon_curve_slajd_2](https://github.com/IS-UMK/2024-js-project-Robert-k0st3k-Walkowski/assets/147077004/0112909b-d905-4e63-934b-dec92db29ff3)

*(Więcej o krzywej smoka i jej stwórcach można poczytać [tutaj](https://en.wikipedia.org/wiki/Dragon_curve) oraz [tutaj](https://pl.wikipedia.org/wiki/Smok_Heighwaya))*

A my za to przejdziemy już do samego problemu badawczego, czyli eksploracji połączeń między naturą, a fraktalami i co do tego ma krzywa smoka???

## Opis problemu badawczego

Na co dzień jest to logiczne, że wokół nas jest pełno mniej lub bardziej fascynującej przyrody. Mam na myśli tutaj chociażby: wielokolorowe drzewa podczas jesieni, różnorodne kształty liści, postawanie różnorodnych i interesujących kształt chmur i wiele, wiele więcej. Wiele tych rzeczy jest często ułożonych w nienaturalne kształty, są w pewnych momentach podobne/powtarzalne, raczej żadne rzeczy w naturze nie mają "trywialnych" struktur i porównując te cechy do cech, jakie ma posiadać obiekt, żeby być "fraktalem" to od razu możemy "połączyć kropki" i stwierdzić, że niejako "otaczają nas fraktale"!😄

Dla potwierdzenia problemu badawczego można przedstawić kilka przykładów w przyrodzie:

1. **Liście i rośliny**
- Struktura liści wielu roślin może przypominać wzory fraktalne, takie jak krzywa smoka. Kiedy liście rozwijają się w sposób spiralny lub mają złożone krawędzie, mogą one tworzyć wzory przypominające fraktale.

![liście](https://github.com/IS-UMK/2024-js-project-Robert-k0st3k-Walkowski/assets/147077004/19be8d05-c8f1-455c-9f1a-3b5f40fd7a5c) ![rośliny](https://github.com/IS-UMK/2024-js-project-Robert-k0st3k-Walkowski/assets/147077004/0b55bd19-0c8b-41f2-9a91-7424685d6dee)

2. **Formacje skalne**
- Pewne formacje skalne, szczególnie te, które powstają w wyniku erozji lub działania sił tektonicznych, mogą tworzyć złożone, samo-podobne wzory przypominające krzywą smoka. Przykładem mogą być niektóre skalne wybrzeża lub kaniony.

![formy_skalne](https://github.com/IS-UMK/2024-js-project-Robert-k0st3k-Walkowski/assets/147077004/314128a5-0e9b-40ad-9898-da902b344c14) ![fomry_skalne_2](https://github.com/IS-UMK/2024-js-project-Robert-k0st3k-Walkowski/assets/147077004/3f60a92d-2198-49a7-8d00-2b03eb2cb652)

3. **Układy chmur**
- Formacje chmur, zwłaszcza te, które powstają w wyniku turbulencji, mogą tworzyć fraktalne wzory. Często widać to w chmurach burzowych lub w układach chmur cirrus, gdzie kształty przypominają złożone krzywe fraktalne.

![chmury_cirrusy](https://github.com/IS-UMK/2024-js-project-Robert-k0st3k-Walkowski/assets/147077004/2b60a365-21f8-4dd0-b6a7-0c61413534d4) ![chmury_burzowe](https://github.com/IS-UMK/2024-js-project-Robert-k0st3k-Walkowski/assets/147077004/9b0710a2-cbb3-42e8-af8d-5cc34807bc89)

4. **Układy korzeni**
- Systemy korzeniowe wielu roślin, szczególnie tych, które rozrastają się w nieregularny sposób w poszukiwaniu wody i składników odżywczych, mogą tworzyć fraktalne wzory. Te wzory mogą przypominać złożone kształty podobne do krzywej smoka.

![korzenie_drzew_1](https://github.com/IS-UMK/2024-js-project-Robert-k0st3k-Walkowski/assets/147077004/24a317ce-0c6f-4955-a38a-32901213a8f1) ![korzenie_drzew_3](https://github.com/IS-UMK/2024-js-project-Robert-k0st3k-Walkowski/assets/147077004/dc1d802e-05f1-4ebb-8aef-0c7a1ba77736)

5. **Pola magnetyczne i linie sił**
- Linie sił pola magnetycznego wokół magnesów lub w ziemskim polu magnetycznym mogą tworzyć skomplikowane, fraktalne wzory, które przypominają krzywą smoka.

![anomalie_w_polu_magnetycznym_ziemi](https://github.com/IS-UMK/2024-js-project-Robert-k0st3k-Walkowski/assets/147077004/ec5363e7-4f7f-46f4-b9e9-a4a6429c2a40) ![pole_magnetyczne_magensu](https://github.com/IS-UMK/2024-js-project-Robert-k0st3k-Walkowski/assets/147077004/8ca821c9-35f9-4671-8568-617a54855ae8)

## Rozwiązanie problemu

Program, który napisałem, generujący nam wspomnianą "krzywą smoka" polega na prostym zobrazowaniu, jak wygląda "krzywa smoka" na różnych jej etapach rozwoju, ponieważ poprzez plik "config.txt" dostępnym na moim repozytorium można wybrać, ile iteracji "krzywej smoka" chcemy zobaczyć **(UWAGA! Dla iteracji większej niż 13, program nie generuje już dalej krzywej smoka w postaci graficznej!)** na ekranie. Jeżeli chodzi o parametry programu, to możemy kontrolować je za pomocą edycji pliku "config.txt", a w nim dane do edycji to: ilość iteracji, szerokość pliku graficznego, wysokość pliku graficznego oraz długość kroku. Zmiany wszystkich tych wartości sprawia, że symulacja oraz graficzna reprezentacja owej symulacji jest różna, w zależności właśnie od podanych wartości. Przyjazny jest ten program również dla użytkownika, ponieważ jest wiele możliwości modyfikacji (np. oparcie go o tablice, zamiast struktury czy wykorzystanie innej biblioteki do generowania graficznego efektu działania programu).

## Przykład użycia programu ukazany przez zrzuty ekranu

**(Wszystko było robione na ustawieniach pliku "config.txt": iter - 10, width - 1200, height - 1200, step - 10)**

<ins>DLA WYBRANIA OPCJI GENEROWANIA GRAFICZNEGO EFEKTU DZIAŁANIA PROGRAMU:<ins>

![screenshot_2](https://github.com/IS-UMK/2024-js-project-Robert-k0st3k-Walkowski/assets/147077004/befd03cc-eebd-4f5a-a86e-43eafb625488) ![screenshot_3](https://github.com/IS-UMK/2024-js-project-Robert-k0st3k-Walkowski/assets/147077004/5fe6a1ff-1e47-4c35-99d0-bf0b648253d3) ![screenshot_5](https://github.com/IS-UMK/2024-js-project-Robert-k0st3k-Walkowski/assets/147077004/d2ef27ba-a714-4c45-bd46-ec8975645516)

<ins>DLA NIE WYBRANIA OPCJI GENEROWANIA GRAFICZNEGO EFEKTU DZIAŁANIA PROGRAMU:<ins>

![screenshot_6](https://github.com/IS-UMK/2024-js-project-Robert-k0st3k-Walkowski/assets/147077004/362aaf78-434c-43a1-a5a3-0e1867bdfcbb) ![screenshot_4](https://github.com/IS-UMK/2024-js-project-Robert-k0st3k-Walkowski/assets/147077004/aee58181-6180-46fc-a1e4-02e625760de8)

## Dodatkowe biblioteki

- ***"turtle.h"** oraz plik do niej **"turtle.c"*** - Jedyna dodatkowa biblioteka dołączona do tego programu, która odpowiada za wspomnianą już nieraz w dokumentacji, generacji graficznego efektu działania programu za pomocą żółwika 🐢 rysującego "krzywą smoka".

## Jak skompilować poprawnie program?

**(UWAGA! Wszystkie operacje kompilacji programu wykonywałem na kompilatorze *<ins>"gcc"<ins>* na systemie operacyjnym *<ins>"Windows 10"<ins>*, ale dla każdego systemu operacyjnego, jeżeli będziemy używać kompilatora *<ins>"gcc"<ins>* wszystko powinno działać poprawnie!)**

1. Pobrać wszystkie pliki z repozytorium i wrzucenie ich do tego samego folderu.

1. Użyć w konsoli komendy *(będąc w lokalizacji/folderze, gdzie pobraliśmy wszystkie pliki do tego programu)*: ***gcc -Wall -Wextra .\krzywa_smoka.c .\turtle.c*** do sprawdzenia, czy program kompiluje się bez żadnych błędów ani ostrzeżeń. Jeżeli wystąpią jakieś problemy, to oznacza, że coś jest nie tak po stronie użytkownika (np. różna lokalizacja plików).

1. Używając konsoli oraz będąc w lokalizacji/folderze z wszystkimi plikami z repozytorium użyć komendy: ***gcc .\krzywa_smoka.c .\turtle.c -o nazwa_outputu*** *(UWAGA! Opcja '-o nazwa_outputu' jest opcjonalna. Jeżeli jej nie użyjemy, to domyślny plik wykonywalny będzie nazywać się "a.exe")*.

1. Dalej będąc w konsoli *(oraz nie zmieniając lokalizacji/folderu!)* użyć komendy: ***.\nazwa_outputu.exe*** (albo ***.\a.exe***, jeżeli nie użyliśmy opcji ***-o nazwa_output***!).

1. PODZIWIAĆ DZIAŁANIE PROGRAMU!!!😎

## Źródła wszystkich obrazów czy opisów:
- Google Grafika

- Wikipedia (https://en.wikipedia.org/wiki/Dragon_curve, https://pl.wikipedia.org/wiki/Smok_Heighwaya, https://pl.wikipedia.org/wiki/Fraktal)

- https://www.mscroggs.co.uk/blog/26 <- Dlaczego "krzywa smoka" nazywamy "krzywą smoka"
