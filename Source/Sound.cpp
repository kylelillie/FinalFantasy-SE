/* FMOD sound system tailord for FFSE */

/*Music*/
short int Fight   = 0;
short int Map     = 1;
short int MTown   = 2;
short int Fanfare = 10;
/*SFX*/
short int Engage  = 3;
short int Attack  = 4;
short int MFire   = 5;
short int MIce    = 6;
short int MBolt   = 7;
short int MCure   = 8;
short int Sword   = 9;


void Play(short int sound)
{	
	FSOUND_Init(44100, 32, 0);
	
	if ( sound == Fight )
	{
	mod = FMUSIC_LoadSong("Media/battle.mid");
	}
	
	if ( sound == Map )
	{
	mod = FMUSIC_LoadSong("Media/map.mid");
	}

	if ( sound == MTown )
	{
	mod = FMUSIC_LoadSong("Media/town.mid");
	}

	if ( sound == Fanfare )
	{
	mod = FMUSIC_LoadSong("Media/fanfare.mid");
	}

	FMUSIC_SetLooping(mod, TRUE);
	FSOUND_INIT_USEDEFAULTMIDISYNTH;
    FMUSIC_PlaySong(mod);
}
void Stop()
{
	FMUSIC_StopSong(mod);
	FMUSIC_FreeSong(mod);
	FSOUND_StopSound (5);
	FSOUND_Sample_Free (sfx);
}
void Pause()
{

}
void SFX(short int sound)
{
/* SFX will use Channel 5 */

	if ( sound == Engage )
	{
	FSOUND_Init(44100, 32, 0);
	sfx=FSOUND_Sample_Load(0,"Media/engage.mp3",0,0,0);
	FSOUND_SetVolume (0,150);
	}

	if ( sound == Sword )
	{
	sfx=FSOUND_Sample_Load(0,"Media/steelsword.wav",0,0,0);
	FSOUND_SetVolume (0,60);
	}

	FSOUND_PlaySound (0,sfx);
}