/** Funktion : Pausiert das Programm fuer x Sekunden
  * Status   : fertig
  */
  void wait()
  {
	  time_t tStart = 0;
	  time_t tStop = 0;
	  double dDiff;
	  tStart=time(NULL);
	  while((dDiff=difftime(tStop,tStart)) != 3)
	  {
		  tStop=time(NULL);
	  }
  }
