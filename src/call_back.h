/*
[18:13] <specing> black_13: sure, export whatever you want to call as a C function
[18:14] == Negr0 [~Negr0@200116b82a09280090d802b1f4a6952a.dip.versatel-1u1.de] has joined #qt
[18:15] == Slesa [~slesa@ANancy-551-1-79-133.w86-204.abo.wanadoo.fr] has quit [Ping timeout: 240 seconds]
[18:15] <thiago> black_13: sure. Call a function that calls your object.
[18:15] <thiago> you provide that function
[18:17] <black_13> that sounds good
*/

#ifdef __cplusplus
extern "C" {
#endif

void call_back(const void *object);

#ifdef __cplusplus
}
#endif