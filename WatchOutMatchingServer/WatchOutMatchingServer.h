#pragma once

#include "../../libppnetwork/libppnetwork/PPTCPIOCPServer.h"
#include "../../libppnetwork/libppnetwork/PPRecvPacketPoolServer.h"
#include "../../libppnetwork/libppnetwork/PPSender.h"
#include "PPProtocolMatchingServer.h"
#include "PPSequence.h"
#include "PPGroup.h"
#include "PPSQL.h"

#ifdef _DEBUG
#pragma comment(lib, "../../libppnetwork/x64/Debug/libppnetwork_d.lib")					//서버 라이브러리의 lib 로드. 실행시 libppnetwork.dll이 반드시 필요합니다.
#else
#pragma comment(lib, "../../libppnetwork/x64/Release/libppnetwork.lib")					//서버 라이브러리의 lib 로드. 실행시 libppnetwork.dll이 반드시 필요합니다.
#endif // DEBUG

namespace PP {
	class WatchOutMatchingServer {
	private:
		PPSQL m_SQL;
	public:
		PPSequence* m_pHead;
	public:
		PPTCPIOCPServer* m_pServer;
		PPSender* m_pSender;
	public:
		WatchOutMatchingServer();
		~WatchOutMatchingServer();
	public:
		int Init();
		int Run();
		int Release();
	public:
		int ProcessPacket();
	};
}
