#ifndef CIP_TECH_DEF
#define CIP_TECH_DEF
#include "mcaRec.h"
#include "tech_def.h"
#include "g_device.h"
#include "PID.h"

#define NOCONC       0.1

///@brief ������������ ����� ������ ��������  
#define PROGRAM_LIST_MAX_LEN 600
///@brief ������������ ����� �������� ��������� ����� 
#define PROGRAM_MAX_LEN 24
///@brief �������� ��� ���������, ������ ����� (��� ����������������)
#define WASH_END_DELAY 2500
///@brief ����������� �������� ������������ ��� ���������� ���������
#define SORT_SWITCH_DELAY 2000
///@brief ����������� ����� ���������� ������� ��� ��������� ��������� ������� ����
#define STEAM_VALVE_MIN_DELAY 1200L

#define TMR_CNT    10
#define SAV_CNT    1

#define ON	1
#define OFF	0

//timers for operations
#define FLIS          1
#define FLNO          0

#define SAV_CONC      0

#define TMR_OP_TIME   0
#define TMR_RETURN    1
#define TMR_CHK_CONC  2
#define TMR_NO_FLOW   9

#define MAX_OP_TIME   2

///@brief ����������� ������ � �3/���, ��� ������� ���������� ��������
#define MIN_FLOW_FOR_HEATING 5

//parameters for main station
#define  P_CZAD_S       0	//������������ �������� �������� ������
#define  P_CMIN_S       1	//����������� ������������ �������� �������� ������	
#define  P_CKANAL_S     2	//������������ ������������ �������� ������ ��� �����������
#define  P_CZAD_K       3	//������������ �������� �������� �������
#define  P_CMIN_K       4	//����������� ������������ �������� �������� �������
#define  P_CKANAL_K     5	//������������ ������������ �������� ������� ��� �����������

#define  P_BLOCK_ERRORS 9   //����� ������ ��� ���������� ������ ������� �����
#define  P_ALFK         10	//����������� ������������� ����������� �������
#define  P_ALFS         11	//����������� ������������� ����������� ������
#define  P_K_S          12	//������������ ����������������� ������
#define  P_K_K          13	//������������ ����������������� �������
#define  P_RO_S         14	//��������� ����������������� ������
#define  P_RO_K         15	//��������� ����������������� �������
#define  P_CONC25S      16	//������������ ������ � �������� �����
#define  P_MS25S        17	//������������ ������ � �������� �����
#define  P_CONC25K      18	//������������ ������� � �������� �����
#define  P_MS25K        19	//������������ ������� � �������� �����
#define  P_MS25W        20	//������������ ���� � �������� �����
#define  P_TM_CHKC      21	//����� ��������� ������������
#define  P_TM_CIRC_RR   22	//����� ���������� ����� ���������� ������������
#define  P_T_RR         23	//����������� ��������� ��� ���������
#define  P_VTANKS       24	//����� ����� ������
#define  P_VTANKK       25	//����� ����� �������
#define  P_VTANKW       26	//�� ������������
#define  P_PDNK         27	//������������������ �������� �������
#define  P_PDNS         28	//������������������ �������� ������
#define  P_FLOW_RR      29	//������������������ ��� ������������� ���������

//programms of moika
#define PRG_SELFCLEAN		11
#define PRG_NAVS            9
#define PRG_NAVK            8
#define PRG_PRO             7
#define PRG_CIRC            6
#define PRG_S               5
#define PRG_K               4
#define PRG_S1              3
#define PRG_D               2
#define PRG_SANITIZER         1
#define PRG_OKO             0

enum selectablePrograms
	{
	SPROG_RINSING_CLEAN = 1,
	SPROG_SANITIZER = 3,
	SPROG_HOTWATER = 5,
	SPROG_RINSING = 128,
	SPROG_RINSING_HOTWATER = 133,
	SPROG_ACID = 144,
	SPROG_ACID_HOTWATER = 149,
	SPROG_CAUSTIC = 160,
	SPROG_CAUSTIC_HOTWATER = 165,
	SPROG_CAUSTIC_ACID = 176,
	SPROG_CAUSTIC_ACID_HOTWATER = 181,
	SPROG_ACID_PREPARATION = 256,
	SPROG_CAUSTIC_PREPARATION = 512,
	SPROG_SELF_CLEAN = 2048,
	};

#define KS_MASK             56

///@brief ������� ������ 
enum MODULE_COMMANDS
	{
	MCMD_NEXT = 1,     
	MCMD_PAUSE,
	MCMD_EVALUATE, 
	MCMD_RESET,
	MCMD_RESET_ALARM,
	MCMD_LOCK_MODULE = 10,
	MCMD_UNLOCK_MODULE,
	MCMD_LOAD_RECIPE = 20,
	MCMD_NEXT_RECIPE,
	MCMD_PREV_RECIPE,
	MCMD_FORCE_RET_ON = 30, //�������������� ��������� ����������� ������
	MCMD_FORCE_RET_OFF,	//�������������� ���������� ����������� ������
	};


enum MODULE_CONSTANTS
	{
	TANK_W,
	TANK_S,
	TANK_K,
	WATER,
	KANAL,
	WITH_WATER,
	WITH_RETURN,
	SHCH,
	KISL,
	HOT_WATER,
	SANITIZER,
#ifdef SELFCLEAN
	NEUTRO,
	TANK_W_MG,
	TANK_W_DREN,
	TANK_S_MG,
	TANK_S_DREN,
	TANK_K_MG,
	TANK_K_DREN,
	TANK_KW_DREN,
	TANK_SW_DREN,
	TANK_SK_DREN,
	TANK_SKW_DREN,
#endif //SELFCLEAN
	};


//errors
#define SERR_UNKNOWN_STEP  -2
#define NO_ACID            -10
#define NO_ALKALINE        -11
#define NO_RETURN          -12
#define ERR_NO_CONC        -13
#define ERR_IS_CONC        -14
#define ERR_WRONG_RET      -15
#define ERR_PUMP           -16
#define ERR_NO_FLOW        -17
#define ERR_AIR            -18
#define ERR_OS             -19
#define ERR_CIP_OBJECT	   -20
#define ERR_WRONG_OS_OR_RECIPE_ERROR	-30
#define ERR_VALVES_ARE_IN_CONFLICT	-31
#define ERR_LEVEL_BACHOK -35
#define ERR_LEVEL_TANK_S -36
#define ERR_LEVEL_TANK_K -37
#define ERR_LEVEL_TANK_W -38
#define ERR_RET            -100


//������������ ������
enum BLOCK_ERRORS
	{
	BE_ERR_LEVEL_BACHOK = 0,
	BE_ERR_LEVEL_TANK_S,
	BE_ERR_LEVEL_TANK_K,
	BE_ERR_LEVEL_TANK_W,
	};


enum workParameters 
	{
	P_CONC_RATE = 1,	//������ ����������� ��� ���������
	P_ZAD_PODOGR,	//������� ������� ���������
	P_ZAD_FLOW,		//������� ������� �������
	P_VRAB,			//�������� ����� ��������
	P_MAX_OPER_TM,	//������������ ����� ������� ��������
	P_OP_TIME_LEFT,	//������ ������� ������� ��������
	P_CONC,			//������� ������������
	P_SUM_OP,		//������ � ������ ��������
	P_ZAD_CONC,		//�������� ������������
	P_LOADED_RECIPE,	//����������� ������

	P_PROGRAM,		//��������� �����

	P_CUR_REC,		//������� ��������� ������
	P_RET_STATE,	//��������� ����������� ������
	P_SELECT_REC,	//�������� �������
	P_SELECT_PRG,	//�������� ���������

	PV1,			//����� V1 (�� ������ �� �������)
	PV2,			//����� V2 (�� ������� �� ������)
	P_OBJ_TYPE,		//��� ������� (����, ����� � ��.)
	P_FLOW,			//������
	P_PODP_CIRC,	//����������� �� ����� �� ����� ����������  
	P_DELTA_TR,		//������� ���������� �� ������ � �������� (���� ������ ��������, �� ���������� ������ ������� ����������)

	P_T_WP,	//����������� ���������������� �������������
	P_T_WSP,	//����������� ������������� �������� ����� ������
	P_T_WKP,	//����������� ������������� �������� ����� �������
	P_T_WOP,	//����������� �������������� �������������
	P_T_S,	//����������� ����� �������
	P_T_K,	//����������� ����� ��������
	P_T_D,	//����������� ����������� �� ����

	P_T_SANITIZER,	//����������� ����������� ��������������� ���������
	P_DOP_V_PR_OP,	//�������������� ����� ���������������� �������������
	P_DOP_V_AFTER_S,	//�������������� ����� ������������� ����� ������
	P_DOP_V_AFTER_K,	//�������������� ����� ������������� ����� �������
	P_DOP_V_OK_OP,		//�������������� ����� �������������� �������������

	P_RET_STOP,	//����� �� ����� V1 ��� ��������� ����������� ������
	P_V_RAB_ML,   //���������� ������ ���� �������� ������ ��� ������� ������������� ���������� ����� ����������
	PV_RET_DEL,	//����� ������� ������ ����� ������ ������ V2 �������� ���������� �����
	PTM_OP,	//����� ���������� ��� ������������� (�������� �� ������������)
	PTM_S,	//����� ���������� �� ������
	PTM_K,	//����� ���������� �� �������
	PTM_S_SK,	//����� ���������� �� ������ ��� ����� �������+������
	PTM_K_SK,	//����� ���������� �� ������� ��� ����� �������+������
	PTM_D,	//����� ����������� �� ����
	PTM_SANITIZER, //����� ����������� ��������������� ���������
	PTM_SANITIZER_INJECT, //����� �������� ���������������� �������� ��� �����������

	P_N_RET,		//����� ����������� ������
	P_N_UPR,		//����� �������� �����
	P_OS,			//�������� �����
	P_OBJ_EMPTY,	//������ "������ ���������"
	P_PROGRAM_MASK, //����� ������� �����
	P_T_CLEAN_RINSING, //����������� ������������� ������ �����
	P_V_CLEAN_RINSING, //����� ������������� ������ �����
	P_RESERV_START,


	STP_QAVS,		//������� ������������ ������
	STP_QAVK,		//������� ������������ �������
	STP_WC,			//������ ����
	STP_WS,			//��������� ����
	STP_LV,			//������������� ��������
	STP_WC_INST_WS,	//������ ����, �������������� �� ������� �������� ���������
	STP_WASH_START, //����� ������ ����� (������������ �������� ��� ��������)
	STP_STEPS_OVER,	//���������� ����������� ��������
	STP_RESETSTEP,	//���, �� ������� ��������
	STP_ERRCOUNT,	//���������� ������
	};

#ifdef SELFCLEAN
enum SELFCLEAN_PARAMS
	{
	SCP_FLOW = 0,			//�������� ������ ����� ������
	SCP_V_TW_PREDV,			//����� ���������������� ������������� ����� ����
	SCP_T_TS_DRAIN,			//����� ����������� ����� ������ (���������)
	SCP_T_TK_DRAIN,			//����� ����������� ����� ������� (���������)
	SCP_T_TW_DRAIN,			//����� ����������� ����� ���� (���������)
	SCP_T_SCH_CIRC_PREDV,	//����� ��������������� ���������� ������ � ����� ������
	SCP_T_K_CIRC_PREDV,		//����� ��������������� ���������� ������� � �� 
	SCP_T_TS_CIRC,			//����� ���������� �������� � �� ����� ������ ������� 
	SCP_T_TK_CIRC,			//����� ���������� �������� � �� ����� ������ ������� 
	SCP_T_TW_CIRC,			//����� ���������� �������� � �� ����� ������ ������� 
	SCP_LITERS_AFTER_LL_TS,	//���-�� � ��� ����������� ����� ������������ �� � ��   
	SCP_LITERS_AFTER_LL_TK,	//���-�� � ��� ����������� ����� ������������ �� � �� 
	SCP_LITERS_AFTER_LL_TW,	//���-�� � ��� ����������� ����� ������������ �� � �� 
	SCP_V_CLEAN_TS,			//����� �������������� ������������� �� ������ �����
	SCP_V_CLEAN_TK,			//����� �������������� ������������� �� ������ �����
	SCP_V_CLEAN_TW,			//����� �������������� ������������� �� ������ �����
	SCP_V_PROM_TS,			//����� �������������� ������������� �� �����
	SCP_V_PROM_TK,			//����� �������������� ������������� �� �����
	SCP_V_PROM_TW,			//����� �������������� ������������� �� �����
	};
#endif // SELFCLEAN

enum storedParameters
	{
	P_TM_RET_IS_EMPTY = 1, //����� ���������� ������� �� �������� ��� ��������� ����������� �������
	P_V_LL_BOT,	//���������� ������ �� ���������� ������� ������ � ����� �� ���������� �������� "����������� �����"
	P_R_NO_FLOW,	//����������� ������ ��� ������� �������, ��� ��� ���
	P_TM_R_NO_FLOW,	//����� ������������� ������ "��� ������� �� ������"
	P_TM_NO_FLOW_R,	//����� ��������� ������ "��� ������� �� ��������"	
	P_TM_NO_CONC,	//����� ��������� ������ "��� ������������ � ���������� �����"
	};

class MSAPIDInterface
	{
	private:
		i_AO_device* output;
		i_AI_device* input;
		unsigned long lastEvalInOnState;
		run_time_params_float*   lineparams;
	public:
		PID* pidr;
		int HI;
		int rp;
		MSAPIDInterface( PID* pid, run_time_params_float* par, int taskpar, i_AO_device* ao = 0, i_AI_device* ai = 0 );
		void eval();
		void reset();
		void on( int accel = 0 );
		void off();
	};

class TSav 
	{
	private:
		float cn;
		unsigned long n;
		unsigned long integrator;
	public:
		TSav(void);
		~TSav(void);
		void Add(float val, unsigned long inegr);
		void R(void);
		float Q(void);
	};

class TPumpController
	{
	private:
		i_DO_AO_device* control_pump;
		int actual_state;
		int manual_state;
		int last_manual_state;
	public:
		TPumpController(i_DO_AO_device* pump);
		~TPumpController();
		virtual void on();
		virtual void off();
		virtual void mOn();
		virtual void mOff();
		virtual void mDisable();
		virtual void Eval();
	};

class cipline_tech_object: public tech_object
	{
	protected:
		int ncmd;

		int ret_circ_flag; //���� ���������� ���������� ������� ��� ����������
		unsigned long ret_circ_delay; //�������� ��������� ��������� ����������� ������
		int ret_overrride; //���� ��������������� ���������/���������� ����������� �������
		int concentration_ok; //���� ������������ �� ��������
		int return_ok; //���� ������ �� ��������
		int tank_is_empty; //������������ ��� ����, ����� ����������, ����� �� ��������� ���������� �����
		unsigned long sort_delay; //������ �������� ��� ���������� ��������� (����� �� ������������� ����������)
		unsigned long steam_valve_delay; //������ �������� ��������� ��������� ������� ���� (����� �� ���������/���������� �� ��������� ��������� �����������)
		unsigned long bachok_lvl_err_delay; //�������� ��� ��������� ������ ������ �����


		unsigned long enddelayTimer;
		int valvesAreInConflict;
		virtual void resetProgramName();
		virtual void resetRecipeName();
		virtual void resetProgramList(unsigned long programmask = 0xB00);
		virtual void formProgramList(unsigned long programmask);
		virtual void loadProgramFromList(int selectedPrg);
		virtual void closeLineValves();
		int isTank();
		int isLine();
		int getValvesConflict();

		//���������� �������� �������
		int pump_control;
		TPumpController* NPC;




	public:
		cipline_tech_object( const char* name, u_int number, u_int type, const char* name_Lua,
			u_int states_count,
			u_int timers_count,
			u_int par_float_count, u_int runtime_par_float_count,
			u_int par_uint_count, u_int runtime_par_uint_count );


		~cipline_tech_object();

		//������ � �����������
		static saved_params<float, true>* parpar;
		float get_station_par(int parno);
		void set_station_par(int parno, float newval);

		//���������� �������� �������
		virtual void EnablePumpController();
		virtual void DisablePumpController();
		virtual void InitPumpController();

		///���� ���������� �������������
		char no_neutro;

		//�������
		TRecipeManager* lineRecipes;
		int loadedRecipe;
		char* loadedRecName;
		char* programList;
		char* currentProgramName;

#ifdef MSAPANEL
		//������ �������� ��� ������
#define PANEL_MAX_PROGRAMS 16
#define PANEL_PROGRAM_LENGTH 24
		char prgArray[PANEL_MAX_PROGRAMS][PANEL_PROGRAM_LENGTH];
		int prgNumber[PANEL_MAX_PROGRAMS];
		char prgListLen;
#endif // MSAPANEL


		int blocked;

		int opcip;
		int curstep;
		int state;
		int curprg;
		int nmr;

		int cip_in_error;

		unsigned long default_programlist; //������ ��������� �������� ����� ��-���������
		int disable_tank_heating; //���������� ��������� ��� ������ ������ ��������� � ����(��� ��� �� ������� ������������� ���������)

		static int blockAlarm;
		static cipline_tech_object* Mdls[10];
		static int MdlsCNT;

#ifdef SELFCLEAN
		i_DO_device* VSMG;
		i_DO_device* VSDREN;
		i_DO_device* VKMG;
		i_DO_device* VKDREN;
		i_DO_device* VWMG;
		i_DO_device* VWDREN;
		static int scline;
		static TParams* scparams;
		virtual int SCInitPumping(int what, int from, int where, int whatdrainage, int step, int f);
		virtual int SCPumping(int what, int from, int where, int whatdrainage);
		int timeIsOut();
		int volumePassed();
#endif //SELFCLEAN
		i_DO_device* V00;
		i_DO_device* V01;
		i_DO_device* V03;
		i_DO_device* V02;
		i_DO_device* V04;
		i_DO_device* V05;
		i_DO_device* V06;
		i_DO_device* V07;
		i_DO_device* V08;
		i_DO_device* V09;
		i_DO_device* V10;
		i_DO_device* V11;
		i_DO_device* V12;
		i_DO_device* V13;

		i_DO_AO_device* NP;
		i_DO_AO_device* NK;
		i_DO_AO_device* NS;
		i_DI_device* LL;
		i_DI_device* LM;
		i_DI_device* LH;
		i_DI_device* LWL;
		i_DI_device* LWH;
		i_DI_device* LSL;
		i_DI_device* LSH;
		i_DI_device* LKL;
		i_DI_device* LKH;
		i_AI_device* TP;
		i_AI_device* TR;
		i_AI_device* Q;
		i_AI_device* ao;
		i_DI_device*FL;
		timer* T[TMR_CNT];
		TSav *SAV[SAV_CNT];
		i_counter *cnt;
		//-------------------

		PID* PIDFlow;
		PID* PIDPump;
		MSAPIDInterface* PIDF;
		MSAPIDInterface* PIDP;
		void initline();

		static int nextpidnumber();
		static int pidnumber;
		static int msa_number;

		//overriden members
		int save_device( char *buff );
		int set_cmd( const char *prop, u_int idx, double val );
		int set_cmd( const char *prop, u_int idx, const char* val );
		int evaluate();

		////-------------------
		virtual void RHI(void);
		virtual void RT(void);
		virtual void PT(void);
		virtual void StopDev(void);
		virtual void ResetLinesDevicesBeforeReset(void);
		virtual int SetCommand(int command);
		virtual int DoStep(int step);
		virtual int GoToStep(int cur, int param);
		virtual int InitStep(int step, int f);
		virtual int LoadProgram(void);
		virtual void ResetWP(void);
		virtual void Stop(int step);
		virtual int SetRet(int val);
		virtual int GetRetState();
		virtual int HasRet();
		virtual void ResetStat(void);
		////-----error service-------
		virtual void ResetErr(void);
		virtual int CheckErr(void);
		////-----for main station----
		virtual void SortRR(int where);
		virtual float GetConc(int what);
		virtual int InitFilRR(int where);
		virtual int InitCircRR(int where);
		virtual int InitCheckConc(int where);
		virtual int InitAddRR(int where);
		virtual int InitOpolRR(int where);
		virtual int FilRR(int where);
		virtual int CircRR(int where);
		virtual int CheckConc(int where);
		virtual int AddRR(int where);
		virtual int OpolRR(int where);
		////-------------------------
		virtual int InitToObject(int from, int where, int step, int f);
		virtual int InitFromObject(int what, int where, int step, int f);
		virtual int InitOporCIP(int where, int step, int f);
		virtual int InitFilCirc(int with_what, int step, int f);
		virtual int InitCirc(int what, int step, int f);
		virtual int InitOporCirc(int where, int step, int f);
		virtual int ToObject(int from, int where);
		virtual int FromObject(int what, int where);
		virtual int OporCIP(int where);
		virtual int FilCirc(int with_what);
		virtual int Circ(int what);
		//virtual int OporCirc(int where);
		//virtual int InitDoseRR(int what, int step, int f);
		//virtual int DoseRR(int what);
		////-------------------
		virtual int EvalBlock();
		////-------------------
		virtual int EvalPIDS();
		virtual int EvalCommands();
		virtual int EvalRecipes();
		virtual int EvalCipInProgress();
		virtual int EvalCipInError();
	};



#endif //CIP_TECH_DEF