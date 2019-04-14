// utilities
#define Q(s) #s
#define ARR2(s0, s1) [(s0), (s1)]
#define ARR3(s0, s1, s2) [(s0), (s1), (s2)]
#define ARR4(s0, s1, s2, s3) [(s0), (s1), (s2), (s3)]
#define ARR5(s0, s1, s2, s3, s4) [(s0), (s1), (s2), (s3), (s4)]
#define LT(n0, n1) if ((n0) < (n1)) then { (n0) } else { (n1) }
#define GT(n0, n1) if ((n0) > (n1)) then { (n0) } else { (n1) }
#define C2(s, s1) s##s1
#define C3(s, s1, s2) s##s1##s2
#define C4(s, s1, s2, s3) s##s1##s2##s3
#define GLUE2(g, s, s1) s##g##s1
#define GLUE3(g, s, s1, s2) s##g##s1##g##s2


// concurrency
#define LOCKED true
#define UNLOCKED false

#define SET(v) isNil { if (v isEqualTo UNLOCKED) then {v = LOCKED; nil} else {false} }
#define LOCK(v) waitUntil { SET(v) }
#define UNLOCK(v) v = UNLOCKED;


// prefixes
#define PREFIX_SEP _
#define PREFIX1(s) C2(s,PREFIX_SEP)
#define PREFIX2(s, s1) C3(s,s1,PREFIX_SEP)
#define PATH_SEP \//
#define PATH1(s) C2(s,PATH_SEP)
#define PATH2(s, s1) C3(s,s1,PATH_SEP)
#define PATH3(s, s1, s2) C4(s,s1,s2,PATH_SEP)

#ifdef AUTHOR
	#define AUTHOR_PREFIX PREFIX1(AUTHOR)
	#define AUTHOR_PATH PATH1(AUTHOR)
#else
	#define AUTHOR_PREFIX
	#define AUTHOR_PATH
#endif

#ifdef MOD
	#define SHARED_PREFIX PREFIX2(AUTHOR_PREFIX,MOD)
	#define SHARED_ADDON C2(AUTHOR_PREFIX,MOD)
	#define SHARED_PATH PATH3(PATH_SEP,AUTHOR_PATH,MOD)
#else
	#define SHARED_PREFIX AUTHOR_PREFIX
	#define SHARED_ADDON AUTHOR
	#define SHARED_PATH
#endif

#ifdef COMPONENT
	#define PREFIX PREFIX2(SHARED_PREFIX,COMPONENT)
	#define ADDON C2(SHARED_PREFIX,COMPONENT)
	#define PATH PATH2(SHARED_PATH,COMPONENT)
#else
	#define PREFIX SHARED_PREFIX
	#define ADDON SHARED_ADDON
	#define PATH SHARED_PATH
#endif

#define VAR(s) C2(PREFIX,s)
#define SETTING(s) C2(PREFIX,GLUE2(_,setting,s))
#define FNC(s) C2(PREFIX,GLUE2(_,fnc,s))
#define FILE(s) C2(PATH,s)

#define SVAR(s) C2(SHARED_PREFIX,s)
#define SSETTING(s) C2(SHARED_PREFIX,GLUE2(_,setting,s))
#define SFNC(s) C2(SHARED_PREFIX,GLUE2(_,fnc,s))
#define SFILE(s) C2(SHARED_PATH,s)
