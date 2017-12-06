int ctrl() 
{
	static int ch = -1, fd = 0;
	struct termios neu, alt;
	fd = fileno(stdin);
	tcgetattr(fd, &alt);
	neu = alt;
	neu.c_lflag &= ~(ICANON|ECHO);
	tcsetattr(fd, TCSANOW, &neu);
	ch = fgetc(stdin);
	tcsetattr(fd, TCSANOW, &alt);
	return ch;
}

int iMenu();

void clr()
{
	printf("\033[1J\033[1;1H");
}

void flush()
{
	int c;
	while( ((c = getchar()) != EOF) && (c != '\n') );
}

void Info_N()
{
	clr();
	printf("\n\n\n");
	printf("                Danke für die Verwendung!");
	fgetc(stdin);
}

void Info_M()
{
	clr();
	printf("\n\n\n");
	printf("                Möchten Sie beenden: Ja/nein? ");
}

void Info_L()
{
	clr();
	printf("\n\n\n");
	printf("                Ihr Dokument enthält folgendes:\n\n");
}

void Info_K()
{
	clr();
	printf("\n\n\n");
	printf("                Welches Dokument möchten Sie löschen?\n\n");
	printf("                ");
}

void Info_J()
{
	clr();
	printf("\n\n\n");
	printf("                Dokument erfolgreich gelöscht!\n");
}

void Info_I()
{
	clr();
	printf("\n\n\n");
	printf("                Welches Dokument möchten Sie kopieren?\n\n");
	printf("                ");
}

void Info_H()
{
	clr();
	printf("\n\n\n");
	printf("                Wie soll die Kopie heißen?\n\n");
	printf("                ");

}

void Info_G()
{
	clr();
	printf("\n\n\n");
	printf("                Dokument erfolgreich kopiert!\n");
}


void Info_F()
{
	clr();
	printf("\n\n\n");
	printf("                In welchem Dokument möchten Sie suchen?\n\n");
	printf("                ");
}

void Info_E()
{
	clr();
	printf("\n\n\n");
	printf("                Nach was möchten Sie suchen?\n\n");
	printf("                ");
}

void Info_D()
{
	clr();
	printf("\n\n\n");
	printf("                Welches Dokument möchten Sie öffnen?\n\n");
	printf("                ");
}

void Info_C()
{
	clr();
	printf("\n\n\n");
	printf("                Welches Dokument möchten Sie bearbeiten?\n\n");
	printf("                ");
}

void Info_B()
{
	clr();
	printf("\n\n\n");
	printf("                Wie soll das Dokument heißen?\n\n");
	printf("                ");
}

void Info_A()
{
	clr();
	printf("\n\n\n");
	printf("                Texteingabe mit CTRL+D beenden\n\n");
}


void Error()
{
	clr();
	printf("\n\n\n");
	printf("                Fehler beim Öffnen! Bitte überprüfen Sie ihre(n) Datei/Pfad!\n");
	fgetc(stdin);
}

void Warnung()
{
	clr();
	printf("\n\n\n");
	printf("                Falsche Taste! Wählen Sie bitte erneut aus!");
	fgetc(stdin);
}

void Screen()
{
	clr();
	printf("\n\n\n");
	printf("                    TEXTEDITOR              (2011)  Nico Anders\n");
	printf("                                                               \n");
	printf("                -N- Neues Dokument                             \n");
	printf("                -A- Dokument fortsetzen                        \n");
	printf("                -O- Dokument Öffnen                            \n");
	printf("                -S- Im Dokument Suchen                         \n");
	printf("                -K- Dokument Kopieren                          \n");
	printf("                -L- Dokument Löschen                           \n");
	printf("                -X- Programm Beenden                           \n");
	printf("                                                               \n");
	printf("                --> Eingabe: ");
}
