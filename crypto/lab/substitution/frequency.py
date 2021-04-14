from operator import itemgetter
def count_letter_frequencies(text):

    frequencies = {}

    for asciicode in range(65, 91):
        frequencies[chr(asciicode)] = 0

    for letter in text:
        asciicode = ord(letter.upper())
        if asciicode >= 65 and asciicode <= 90:
            frequencies[chr(asciicode)] += 1

    sorted_by_frequency = sorted(frequencies.items(), key = itemgetter(1), reverse=True)

    return sorted_by_frequency
    
    
def main():
    cipher = "IJEICWDRCEPHLM MLDRPG LK C KNEKHLHNHLJE MLDRPG LE ZRLMR VIG C BLAPE XPT HRP MLDRPG CWDRCFPH VJG PCMR DWCLE CWDRCFPH LK VLOPY HRGJNBRJNH HRP PEMGTDHLJE DGJMPKK VJG POCIDWP LV C LX PEMGTDHPY CK Y VIG CET ENIFPG JV JMMNGGPEMP LE  HRCH DWCLEHPOH C ZLWW CWZCTK BPH PEMGTDHPY HJ Y CWW JV HRP KNFKHLHNHLJE MLDRPGK ZP RCAP YLKMNKKPY PCGWLPG LE HRLK MRCDHPG CGP IJEJCWDRCEPHLM HRPKP MLDRPGK CGP RLBRWT  KNKMPDHLFWP HJ MGTDHCECWTKLK DJWTCWDRCFPHLM MLDRPG LK C KNFKHLHNHLJE MLDRPG LE ZRLMR HRP MLDRPG CWDRCFPH VJG HRP DWCLE CWDRCFPH ICT FP YLVVPGPEH CH YLVVPGPEH DWCMPK YNGLEB HRP PEMGTDHLJE DGJMPKK HRP EPOH HZJ POCIDWPK DWCTVCLG CEY ALBPEPGP MLDRPG CGP DJWTCWDRCFPHLM MLDRPGK"
    
    print(count_letter_frequencies(cipher))
    
if __name__ == '__main__':
    main()
