
#ifndef _940SHARED_H_
#define _940SHARED_H_

#define ENABLE_940T

// max 16 jobs
enum _940_job_t {
	JOB940_INITALL = 1,
	JOB940_INVALIDATE_DCACHE,
	JOB940_RUN_Z80,
	JOB940_RUN_Z80_BIS,
};

//#define MAX_940JOBS	2

typedef struct
{
	unsigned int z80_cycle;
	unsigned int sample_rate;
	unsigned char *pcmbufa;
	unsigned char *pcmbufb;
	unsigned int pcmbufa_size;
	unsigned int pcmbufb_size;
	unsigned char *sm1;
	/* TODO ym2610 + Z80 data */
} _940_data_t;


#define SAMPLE_BUFLEN 16384

typedef struct
{
	int		vstarts[8];				/* debug: 00: number of starts from each of 8 vectors */
	int		last_lr;				/* debug: 20: last exception's lr */
//	int		jobs[MAX_940JOBS];			/* jobs for second core */
//	int		busy_;					/* unused */
	int		lastjob;			/* debug: last job id */
	int             loopc;
	/* TODO Sound latch register */
	int test;
	int result_code;
	int sound_code;
	int pending_command;
	int nmi_pending;
	int z80_run;
	int z80_render_a_frame;
	int updateym;
	unsigned int buf_pos;
	unsigned short play_buffer[SAMPLE_BUFLEN];

} _940_ctl_t;

extern volatile _940_data_t *shared_data;
extern volatile _940_ctl_t  *shared_ctl;

#endif