# Turok 3 Reverse Engineering

## Map

##### **Notes**

###### The US release of the game was compiled with O3
###### The virtual address of most functions are: address - 0x200000 + 0x80000000

### Function Map

|Name                                      |Location|Function Signature                                                                                                                                                                                                                                                             |Function Size|
|------------------------------------------|--------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------|
|romMain                                   |80000400|void romMain(void)                                                                                                                                                                                                                                                        |136          |
|main                                      |0020aa50|int main(void)                                                                                                                                                                                                                                                        |112          |
|COnScreen__SetFontIndex                   |0020c0f0|void COnScreen__SetFontIndex(int index)                                                                                                                                                                                                                               |717          |
|COnScreen__DrawText                       |0020c948|void COnScreen__DrawText(char* String, int nX, int nY, int Opacity, int centre, int shadow, float ScaleX, float ScaleY)                                                                                                                                              |660          |
|COnScreen__SetFontColor                   |0020efd0|void COnScreen__SetFontColor(int tr, int tg, int tb, int br, int bg, int bb)                                                                                                                                                                                          |44           |
|COnScreen__SetFontScale                   |0020f03c|void COnScreen__SetFontScale(float XScale, float YScale)                                                                                                                                                                                                              |20           |
|CEngineApp__GetNumPlayers                 |00211bb8|int CEngineApp__GetNumPlayers(void)                                                                                                                                                                                                                                   |73           |
|memset                                    |0021e500|int memset(void* src, int value, int length)                                                                                                                                                                                                                         |12           |
|VM_Initialize                             |00225440|void VM_Initialize(char* a0, char* a1)                                                                                                                                                                                                                         |624          |
|CCollisionInfo__Reset                     |002291a0|void CCollisionInfo__Reset(void)                                                                                                                                                                                                                                      |52           |
|CIN_Update_Time                           |00231ddc|void CIN_Update_Time(void)                                                                                                                                                                                                                                            |101          |
|osSetEventMesg                            |00232574|int osSetEventMesg(int param_1, void* param_2, void* param_3)                                                                                                                                                                                               |140          |
|CIN_Playing                               |00232718|int CIN_Playing(void)                                                                                                                                                                                                                                                 |20           |
|CIN_PathPlaying                           |0023272c|int CIN_PathPlaying(void)                                                                                                                                                                                                                                             |72           |
|CinemaMoveHook                            |002327f8|void CinemaMoveHook(void)                                                                                                                                                                                                                                             |48           |
|CGameObjectInstance__Construct            |00233770|void CGameObjectInstance__Construct(CGameObjectInstance* pThis, int nObjIndex, int nObjTypeFlag, int param_4, CIntelligenceBase* pIntel, int param_6, float RotY, CVector3 vPos, uint32_t dwFlags, CVector3 vScale, CVector3 vVelocity, int InstanceFlag)           |1436         |
|CGameObjectInstance__LookupAIAnimType     |00233d60|int CGameObjectInstance__LookupAIAnimType(CGameObjectInstance* pThis, int nType, int nSkipIndex)                                                                                                                                                                     |1111         |
|CGameObjectInstance__SetDesiredAnim       |00238c80|void CGameObjectInstance__SetDesiredAnim(CGameObjectInstance* pThis, int nAnim)                                                                                                                                                                                 |32           |
|CGameObjectInstance__RestartAnim          |00238ca0|void CGameObjectInstance__RestartAnim(CGameObjectInstance* pThis)                                                                                                                                                                                                    |36           |
|CGameObjectInstance__SetDesiredAnimByType |00238cc4|int CGameObjectInstance__SetDesiredAnimByType(CGameObjectInstance* pThis, int nAnim, int InterruptBlend)                                                                                                                                                             |85           |
|CGameObjectInstance__SetDesiredAnimByIndex|00238d18|int CGameObjectInstance__SetDesiredAnimByIndex(CGameObjectInstance* pThis, int nAnim, int InterruptBlend)                                                                                                                                                            |81           |
|CGameObjectInstance__ChooseRandomAnim     |00238d5c|int CGameObjectInstance__ChooseRandomAnim(CGameObjectInstance* pThis, void* pAnimList, int nSkipIndex)                                                                                                                                                              |172          |
|CGameObjectInstance__Draw_Player          |00238ef0|void CGameObjectInstance__Draw_Player(CGameObjectInstance* pThis, CIntelligenceBase* pAI, uint8_t* pDrawInfo)                                                                                                                                                       |273          |
|CCache__Construct                         |0023ecf0|void CCache__Construct(void* dummy, int ThreadID)                                                                                                                                                                                                                    |738          |
|CCache__AllocMemEntry                     |0023f2d8|void* CCache__AllocMemEntry(int dwFlags)                                                                                                                                                                                                                           |277          |
|CCache__RequestAndLock                    |0023f734|void* CCache__RequestAndLock(void* dummy, void* pAddress, uint32_t length, uint32_t dwFlags, void* pNotifyID, void* DecompressCallback, char* szDescription, int Synchronous)                                                                                   |1568         |
|CCache__AllocateAndLock                   |00240c98|void* CCache__AllocateAndLock(int Length, uint32_t dwFlags, char* szDescription)                                                                                                                                                                                    |242          |
|CCache__DListStart                        |00240fc8|void CCache__DListStart()                                                                                                                                                                                                                                        |240          |
|CCache__Deallocate                        |002411c0|void CCache__Deallocate(void* pEntry)                                                                                                                                                                                                                           |320          |
|CCache__Compress                          |0024128c|void CCache__Compress(void)                                                                                                                                                                                                                                           |238          |
|CCache__DeallocAndReplaceCompressedData   |0024136c|void CCache__DeallocAndReplaceCompressedData(void* pCacheEntry, void* pNewData)                                                                                                                                                                                     |268          |
|CCache__LoadPersistantIndex               |002416f0|void* CCache__LoadPersistantIndex(void* ppisDest, void* rpAddress, char* szDescription)                                                                                                                                                                           |592          |
|CCache__LoadPersistantSubBlock            |00241860|void* CCache__LoadPersistantSubBlock(void* pisSourceIndex, int nBlock, void* rpBaseAddress, void* pNotifyID, void* pfnDecompress, char* szDescription)                                                                                                          |116          |
|CCache__AllocateMemoryForDecompression    |002418d4|void* CCache__AllocateMemoryForDecompression(void* pCacheEntry, int length)                                                                                                                                                                                         |350          |
|CCache__SetSyncCount                      |00241b68|void CCache__SetSyncCount(int nFrames)                                                                                                                                                                                                                                |16           |
|CDecompressor__Construct                  |00242360|void CDecompressor__Construct(int param_1, int param_2)                                                                                                                                                                                                   |56           |
|CDecompressor__Flush                      |002424b0|void CDecompressor__Flush(void* pThis)                                                                                                                                                                                                                               |88           |
|CDecompressor__Main                       |00242508|void CDecompressor__Main(void* pThis)                                                                                                                                                                                                                                |176          |
|CHashTable__Construct                     |00242570|void CHashTable__Construct(uint32_t param_1)                                                                                                                                                                                                                         |212          |
|CHeap__Dealloc                            |00242a10|void CHeap__Dealloc(CHeap* pThis, void* pAddress)                                                                                                                                                                                                                   |289          |
|CHeap__Construct                          |00242b30|void CHeap__Construct(CHeap* pThis, void* pAddress, uint32_t length)                                                                                                                                                                                           |108          |
|CHeap__Alloc                              |00242b9c|void* CHeap__Alloc(CHeap* pThis, uint32_t length)                                                                                                                                                                                                                   |276          |
|CHeap__AllocTop                           |00242cb0|int* CHeap__AllocTop(CHeap* pThis, uint32_t length)                                                                                                                                                                                                          |248          |
|CHeap__DeallocAll                         |00242da8|void CHeap__DeallocAll(CHeap* pThis)                                                                                                                                                                                                                                 |21           |
|CHeap__FreeMem                            |00242de8|void CHeap__FreeMem(CHeap* pThis, uint32_t* pTotal, uint32_t* pLargest)                                                                                                                                                                                            |80           |
|CList__Construct                          |00242e40|void CList__Construct(void* pThis, uint32_t LastOffset, uint32_t NextOffset)                                                                                                                                                                                         |24           |
|CList__AddHead                            |00242e58|void CList__AddHead(void* pThis, void* pEntry)                                                                                                                                                                                                                 |93           |
|CList__AddTail                            |00242eb4|void CList__AddTail(void* pThis, void* pEntry)                                                                                                                                                                                                                      |92           |
|CList__InsertBefore                       |00242f10|void CList__InsertBefore(void* pThis, void* pTarget, void* pNewEntry)                                                                                                                                                                                              |172          |
|CList__InsertAfter                        |00242fc4|void CList__InsertAfter(void* pThis, void* pTarget, void* pNewEntry)                                                                                                                                                                                               |193          |
|CList__Remove                             |00243078|void CList__Remove(void* pThis, void* pEntry)                                                                                                                                                                                                                  |152          |
|CList__RemoveHead                         |00243110|void CList__RemoveHead(void* pThis)                                                                                                                                                                                                                                  |36           |
|CList__RemoveTail                         |00243134|void CList__RemoveTail(void* pThis)                                                                                                                                                                                                                                  |36           |
|CLoader__Construct                        |00243420|void CLoader__Construct(int param_1, int param_2)                                                                                                                                                                                                         |172          |
|CLoader__LoadSync                         |0024351c|void CLoader__LoadSync(void* pThis, void* pAddress, int length, void* pDest)                                                                                                                                                                                       |216          |
|CLoader__LoadAsync                        |002435f4|void CLoader__LoadAsync(void* pThis, void* pAddress, int length, void* pDest, void* pReplyQueue, void* pReplyMessage, int HighPriority)                                                                                                                          |316          |
|CLoader__Main                             |0024371c|void CLoader__Main(void* pThis)                                                                                                                                                                                                                                      |289          |
|CLoader__AllocLoaderEntry                 |0024383c|CLoaderEntry* CLoader__AllocLoaderEntry(void* pThis)                                                                                                                                                                                                                |108          |
|CLoader__DeallocLoaderEntry               |002438a8|void CLoader__DeallocLoaderEntry(void* pThis, CLoaderEntry* pEntry)                                                                                                                                                                                                 |96           |
|CMutex__Construct                         |002439c4|void CMutex__Construct(void* pThis)                                                                                                                                                                                                                                  |36           |
|InitializeSystemResources                 |002439f0|void InitializeSystemResources(void)                                                                                                                                                                                                                             |184          |
|CAudioWorld__killType                     |00245c40|void CAudioWorld__killType(void* pThis, int Type)                                                                                                                                                                                                               |1333         |
|CLoopingSoundPool__Construct              |00249ef8|void CLoopingSoundPool__Construct(void* pThis, void* pLoopingSoundDataVars, int nSounds)                                                                                                                                                                            |132          |
|CLoopingSoundPool__HaltAll                |0024a204|void CLoopingSoundPool__HaltAll(int param_1)                                                                                                                                                                                                                     |128          |
|GetLoopingSoundPool                       |0024a284|int GetLoopingSoundPool(void)                                                                                                                                                                                                                                  |16           |
|Sound__Initialize                         |0024b604|void Sound__Initialize(void)                                                                                                                                                                                                                                     |36           |
|Sound__StopFlags                          |0024baa8|void Sound__StopFlags(int flags)                                                                                                                                                                                                                                 |40           |
|Sound__NullAllVectorPointers              |0024bd24|void Sound__NullAllVectorPointers(void)                                                                                                                                                                                                                               |36           |
|GAS_Construct                             |0024fe1c|void GAS_Construct(CAnimationState* pThis)                                                                                                                                                                                                                      |40           |
|InitAllRumblePaks                         |00252414|void InitAllRumblePaks(void)                                                                                                                                                                                                                                     |72           |
|EnableAllRumblePaks                       |0025245c|void EnableAllRumblePaks(int param_1)                                                                                                                                                                                                                            |116          |
|CCrash__Construct                         |002526b0|void CCrash__Construct(void)                                                                                                                                                                                                                                     |8            |
|osGetMemSize                              |00252c80|uint32_t osGetMemSize(void)                                                                                                                                                                                                                                               |40           |
|strcmp                                    |00252e18|int strcmp(char* lhs, char* rhs)                                                                                                                                                                                                                                    |128          |
|strcpy                                    |00252e98|char* strcpy(char* dest, char* src)                                                                                                                                                                                                                                |56           |
|unk_zero_or_one_f0                        |00253164|float unk_zero_or_one_f0(void)                                                                                                                                                                                                                                        |76           |
|CGeometry__Decompress                     |00259768|void CGeometry__Decompress(void* pVoid, void* pCacheEntry, int bAnimated, int bMorph)                                                                                                                                                                               |724          |
|CGeometry__DecompressStaticObject         |0025dc6c|void CGeometry__DecompressStaticObject(void* pVoid, void* pCacheEntry)                                                                                                                                                                                              |32           |
|CGeometry__DecompressSimpleObject         |0025dc8c|void CGeometry__DecompressSimpleObject(void* pVoid, void* pCacheEntry)                                                                                                                                                                                              |32           |
|CGeometry__DecompressAnimatedObject       |0025dcac|void CGeometry__DecompressAnimatedObject(void* pVoid, void* pCacheEntry)                                                                                                                                                                                            |32           |
|CGeometry__ResetDrawModes                 |0025dde8|void CGeometry__ResetDrawModes(void)                                                                                                                                                                                                                                  |28           |
|CMtxF__Identity                           |00262768|void CMtxF__Identity(float* lhs)                                                                                                                                                                                                                                |80           |
|CMtxF__Rotate                             |00262ca4|void CMtxF__Rotate(CMtxF* mfThis, float Theta, float X, float Y, float Z)                                                                                                                                                                                            |4            |
|CSelectionList__Construct                 |0026a95c|void CSelectionList__Construct(void* pThis)                                                                                                                                                                                                                          |8            |
|CSelectionList_AddItem                    |0026a964|int CSelectionList_AddItem(void* pThis, int16_t Item, int16_t weight)                                                                                                                                                                                         |68           |
|CSelectionList__ChooseItem                |0026a9a8|void CSelectionList__ChooseItem(void* pThis)                                                                                                                                                                                                                    |125          |
|CMatrixPool__Advance                      |0026aa90|void CMatrixPool__Advance(CMatrixPool* pThis)                                                                                                                                                                                                                        |48           |
|CParticleSystem__Advance                  |00274744|void CParticleSystem__Advance(void* pThis)                                                                                                                                                                                                                           |998          |
|ProPackDecompress                         |00276270|int ProPackDecompress(void* pCacheEntry, int IntermediateStep)                                                                                                                                                                                                       |307          |
|CScene__Draw                              |00277420|void CScene__Draw(CScene* pThis, int param_2, int param_3, int param_4)                                                                                                                                                                                |480          |
|CScene__LoadLevel                         |00277bb0|void CScene__LoadLevel(CScene* pThis, int nLevel, int GoToWarpPoint)                                                                                                                                                                                                 |1152         |
|CScene__SetupActiveAnimInstances          |00279248|void CScene__SetupActiveAnimInstances(CScene* pThis)                                                                                                                                                                                                                 |2214         |
|CScene__LoadActiveGridSections            |0027987c|void CScene__LoadActiveGridSections(CScene* pThis)                                                                                                                                                                                                                   |1473         |
|CScene__BuildInstanceCollisionList        |00279d5c|void CScene__BuildInstanceCollisionList(CScene* pThis)                                                                                                                                                                                                               |909          |
|CScene__LookupObjectType                  |0027de0c|int CScene__LookupObjectType(void* pThis, int nType)                                                                                                                                                                                                                 |64           |
|CScene__LoadObjectModelType               |0027de64|void CScene__LoadObjectModelType(void* pThis, void* pInstance, int nObjectType, int nAnimType)                                                                                                                                                                      |132          |
|CScene__GetRegionAttributes               |0027dee8|void* CScene__GetRegionAttributes(void* pThis, void* pRegion)                                                                                                                                                                                                      |88           |
|CScene__GetObjectAddress                  |0027f05c|void* CScene__GetObjectAddress(void* pThis, int nObject)                                                                                                                                                                                                            |60           |
|CScene__GetLevelName                      |00280444|void CScene__GetLevelName(CScene* pThis, int nLevel, char* pBuffer, int BufferLength)                                                                                                                                                                               |368          |
|CScene_ClearListCounts                    |00280784|void CScene_ClearListCounts(CScene* pThis)                                                                                                                                                                                                                           |48           |
|CScene__UnlockActiveGridSections          |00280b44|void CScene__UnlockActiveGridSections(CScene* pThis)                                                                                                                                                                                                                 |56           |
|osCreateScheduler                         |0028280c|void osCreateScheduler(short* param_1, undefined param_2, undefined param_3, undefined param_4, undefined1 param_5)                                                                                                                                        |272          |
|osScAddClient                             |0028291c|void osScAddClient(int param_1, int* param_2, int param_3)                                                                                                                                                                                        |88           |
|CISet__GetBlock                           |00282e64|void* CISet__GetBlock(void* pISet, int nBlock)                                                                                                                                                                                                                      |20           |
|CISet__GetBlockAndSize                    |00282e78|int CISet__GetBlockAndSize(void* pISet, int nBlock, int* pLength)                                                                                                                                                                                                   |48           |
|CISet__GetROMAddress                      |00282ed8|void* CISet__GetROMAddress(void* pISet, void* pBase, int nBlock)                                                                                                                                                                                                   |20           |
|CISet__GetROMAddressAndSize               |00282eec|void* CISet__GetROMAddressAndSize(void* pISet, void* pBase, int nBlock, int* pLength)                                                                                                                                                                             |48           |
|CEngineApp__ClearZBuffer                  |00283e80|void CEngineApp__ClearZBuffer(int param_1, uint32_t param_2, uint32_t param_3)                                                                                                                                                                                    |388          |
|CEngineApp__Construct                     |00284208|void CEngineApp__Construct(void* pThis)                                                                                                                                                                                                                         |80           |
|CEngineApp__Main                          |002844a8|void CEngineApp__Main(uint8_t* pThis)                                                                                                                                                                                                                                |1347         |
|CEngineApp__Draw                          |00285424|void CEngineApp__Draw(void* pThis)                                                                                                                                                                                                                                   |858          |
|CEngineApp__Update                        |0028577c|void CEngineApp__Update(void* pThis)                                                                                                                                                                                                                                 |1092         |
|boot                                      |00285bbc|void boot(void)                                                                                                                                                                                                                                                  |36           |
|CEngineApp__Boot                          |00285be0|void CEngineApp__Boot(void* pThis)                                                                                                                                                                                                                                   |40           |
|CEngineApp__Idle                          |00285c58|void CEngineApp__Idle(void* pThis, void* pArg)                                                                                                                                                                                                                      |40           |
|CEngineApp__AdvanceFrameData              |00285cd8|void CEngineApp__AdvanceFrameData(void* pThis)                                                                                                                                                                                                                       |209          |
|CEngineApp__SetPlayers                    |00285e00|void CEngineApp__SetPlayers(void* pThis, int nPlayers)                                                                                                                                                                                                               |80           |
|idle                                      |00285f10|void idle(void)                                                                                                                                                                                                                                                       |40           |
|mainproc                                  |00285f38|void mainproc(void* pArg)                                                                                                                                                                                                                                            |92           |
|CEngineApp__SetupFadeTo                   |00286058|void CEngineApp__SetupFadeTo(int param_1, int param_2)                                                                                                                                                                                                    |36           |
|CEngineApp__DrawTextScreen                |0028607c|void CEngineApp__DrawTextScreen(void* pThis, int bClearScreen, char* * ppText, int X, int Y, int IncY, float ScaleX, float ScaleY)                                                                                                                                  |48           |
|CEngineApp__Retrace                       |0028620c|void CEngineApp__Retrace(int param_1)                                                                                                                                                                                                                            |188          |                                                                                                                                                                                                                                                 |28           |
|unk_SetupGameAndLevel                     |0028653c|void unk_SetupGameAndLevel(void* pThis)                                                                                                                                                                                                                              |56           |
|CEngineApp__SetupGame                     |00286610|void CEngineApp__SetupGame(void* pThis)                                                                                                                                                                                                                              |392          |
|CMenuPool__Draw                           |0028d318|void CMenuPool__Draw(void* pThis)                                                                                                                                                                                                                                    |722          |
|CCamera__AdvanceAttributes                |0028dc18|void CCamera__AdvanceAttributes(CCamera* pThis)                                                                                                                                                                                                                      |1803         |
|CCamera__Advance                          |0028ea30|void CCamera__Advance(CCamera* pThis)                                                                                                                                                                                                                                |40           |
|CCamera__DisplayListSetup                 |0028f50c|void CCamera__DisplayListSetup(void* pThis)                                                                                                                                                                                                                          |424          |
|CCameraPool__DrawScene                    |0029094c|void CCameraPool__DrawScene(void* pThis)                                                                                                                                                                                                                             |148          |
|CCameraPool__AdvanceText                  |00291794|void CCameraPool__AdvanceText(void* pThis, void* pCamera)                                                                                                                                                                                                           |40           |
|CCamera__DrawScene                        |002923b4|void CCamera__DrawScene(void* pThis, CScene* pScene)                                                                                                                                                                                                                |116          |
|CCameraViewParams__Construct              |00292b88|void CCameraViewParams__Construct(void* pThis)                                                                                                                                                                                                                       |108          |
|CCamera__SetupMode                        |00292dc8|void CCamera__SetupMode(CCamera* pThis, int NewMode)                                                                                                                                                                                                                 |72           |
|CCamera__InitializeWarp                   |002931fc|void CCamera__InitializeWarp(CCamera* pThis)                                                                                                                                                                                                                         |44           |
|CCameraPool__DrawTints                    |0029331c|void CCameraPool__DrawTints(void)                                                                                                                                                                                                                                |8            |
|CCameraPool__AddMultiLineText             |00293614|void* CCameraPool__AddMultiLineText(void* pThis, void* pCamera, char* pString, float Secs)                                                                                                                                                                        |64           |
|CCamera__LevelStart                       |00293c90|void CCamera__LevelStart(CCamera* pThis)                                                                                                                                                                                                                             |28           |
|CCameraText__Construct                    |00293d50|void CCameraText__Construct(void* pThis)                                                                                                                                                                                                                        |12           |
|CGameObjectInstance__Draw                 |00296f1c|void CGameObjectInstance__Draw(CGameObjectInstance* pThis, CIntelligenceBase* pAI, uint8_t* pDrawInfo)                                                                                                                                                              |784          |
|AI_UpdateAnimation                        |002beb4c|void AI_UpdateAnimation(CGameObjectInstance* pThis, void* pAI)                                                                                                                                                                                                      |932          |
|CGameObjectInstance__Draw                 |002c6788|void CGameObjectInstance__Draw(CGameObjectInstance* pThis, CIntelligenceBase* pAI, uint8_t* DrawInfo)                                                                                                                                                               |2539         |
|CGameObjectInstance__Draw                 |002c696c|void CGameObjectInstance__Draw(CGameObjectInstance* pThis, CIntelligenceBase* pAI, uint8_t* pDrawInfo)                                                                                                                                                              |1053         |
|CPlayerPool__AdvancePlayerWeapons         |002d42cc|void CPlayerPool__AdvancePlayerWeapons(void* pThis, int param_2, int param_3, int param_4)                                                                                                                                                             |404          |
|CPlayerPool__PrepareForDraw               |002d4fb8|void CPlayerPool__PrepareForDraw(void* pThis)                                                                                                                                                                                                                        |116          |
|CPlayerPool__GetSinglePlayer              |002d52c8|void* CPlayerPool__GetSinglePlayer(void* pThis)                                                                                                                                                                                                                     |12           |
|CPlayer__SetDeathmatchIntelligence        |002d76b8|void CPlayer__SetDeathmatchIntelligence(void* pThis)                                                                                                                                                                                                                 |212          |
|CPlayer__LoadCharacterObjectType          |002d778c|void CPlayer__LoadCharacterObjectType(void* pThis)                                                                                                                                                                                                                   |209          |
|CGameObjectInstance_Draw_Weapon           |002da48c|void CGameObjectInstance_Draw_Weapon(CGameObjectInstance* pThis, CIntelligenceBase* pAI, uint8_t* pDrawInfo)                                                                                                                                                  |533          |
|osStartThread                             |002dda10|void osStartThread()                                                                                                                                                                                                                                             |296          |
|osCreateThread                            |002ddb30|void osCreateThread(int* param_1, int param_2, int param_3, int param_4, void* param_5, int param_6)                                                                                                                               |216          |
|osCreateMesgQueue                         |002ddd20|void osCreateMesgQueue(int* param_1, int param_2, int param_3)                                                                                                                                                                             |36           |
|osSendMesg                                |002ddd50|int osSendMesg(int* * param_1, int param_2, int param_3)                                                                                                                                                                                                      |341          |
|osRecvMesg                                |002dde80|int osRecvMesg(int param_1, int* param_2, int param_3)                                                                                                                                                                                                 |293          |
|memcpy                                    |002ddfb0|void* memcpy(void* src, void* dest, int length)                                                                                                                                                                                                                    |40           |
|cosf                                      |002de040|void cosf()                                                                                                                                                                                                                                                      |68           |
|sinf                                      |002de150|float sinf()                                                                                                                                                                                                                                                      |92           |
|SQRT                                      |002de2d0|float SQRT(float param_1)                                                                                                                                                                                                                                             |12           |
|sprintf                                   |002de2e0|int sprintf(char* str, char* fmt, ...)                                                                                                                                                                                                                              |88           |
|osInitialize                              |002de360|void osInitialize(void)                                                                                                                                                                                                                                               |546          |
|osInvalDCache                             |002dee10|void osInvalDCache(uint32_t param_1, uint32_t param_2)                                                                                                                                                                                                                   |152          |
|__osDisableInt                            |002def00|int __osDisableInt(void)                                                                                                                                                                                                                                              |32           |
|__osRestoreInt                            |002def20|void __osRestoreInt(uint32_t param_1)                                                                                                                                                                                                                                |28           |
|osJamMesg                                 |002def40|int osJamMesg(int** param_1, int param_2, int param_3)                                                                                                                                                                                                       |364          |
|osSetThreadPri                            |002df080|void osSetThreadPri(int param_1, int param_2)                                                                                                                                                                                                                             |196          |
|osSetTimer                                |002df150|int osSetTimer(int* param_1, int param_2, uint32_t param_3, uint32_t param_4, int param_5, int param_6, int param_7, int param_8)                                                                                           |140          |
|osWriteBackDCache                         |002df1e0|void osWriteBackDCache(uint32_t param_1, uint32_t param_2)                                                                                                                                                                                                               |104          |
|osPiRawStartDma                           |002df250|int osPiRawStartDma(int param_1, uint32_t param_2, int param_3, int param_4)                                                                                                                                                                                |212          |
|alSndpSetFXMix                            |002dfd00|void alSndpSetFXMix(int param_1, undefined param_2)                                                                                                                                                                                                                       |76           |
|alSndpSetPitch                            |002dfd50|void alSndpSetPitch(int param_1, int param_2)                                                                                                                                                                                                                      |76           |
|alSndpSetPan                              |002e04d0|void alSndpSetPan(int param_1, undefined param_2)                                                                                                                                                                                                                         |76           |
|alSndpSetVol                              |002e0520|void alSndpSetVol(int param_1, short param_2)                                                                                                                                                                                                                        |76           |
|alSndpStop                                |002e0670|void alSndpStop(int param_1)                                                                                                                                                                                                                                              |72           |
|alSndpPlay                                |002e0780|void alSndpPlay(int param_1)                                                                                                                                                                                                                                              |96           |
|osViSetYScale                             |002e4d10|void osViSetYScale(int param_1)                                                                                                                                                                                                                                    |68           |
|osSpTaskYield                             |002e4d60|void osSpTaskYield(void)                                                                                                                                                                                                                                                  |28           |
|osViBlack                                 |002e4dd0|void osViBlack(int set_black)                                                                                                                                                                                                                                         |93           |
|osViSwapBuffer                            |002e4e30|void osViSwapBuffer(int param_1)                                                                                                                                                                                                                                   |68           |
|osViSetSpecialFeatures                    |002e5140|void osViSetSpecialFeatures(uint32_t param_1)                                                                                                                                                                                                                                 |356          |
|__osGetFpcCsr                             |002e5360|uint32_t __osGetFpcCsr(void)                                                                                                                                                                                                                                          |12           |
|__osSetFpcCsr                             |002e5370|void __osSetFpcCsr(uint32_t fpstat)                                                                                                                                                                                                                                   |16           |
|osCreateViManager                         |002e5380|void osCreateViManager(int param_1)                                                                                                                                                                                                                              |368          |
|guLookAtF                                 |002e5900|void guLookAtF(float* mf, float xEye, float yEye, float zEye, float xAt, float yAt, float zAt, float xUp, float yUp, float zUp)                                                                                                                                      |24           |
|alSynAddPlayer                            |002ea9c0|void alSynAddPlayer(int* param_1, int* param_2)                                                                                                                                                                                                           |80           |
|alSynFreeVoice                            |002eaa10|void alSynFreeVoice(int param_1, int param_2)                                                                                                                                                                                                                             |160          |
|alSynStopVoice                            |002eaab0|void alSynStopVoice(int param_1, int param_2)                                                                                                                                                                                                                             |124          |
|readVarLen                                |002ef9d8|void readVarLen(int* param_1, int param_2, int param_3)                                                                                                                                                                                             |224          |
|PAK_InitSystem                            |00405150|void PAK_InitSystem(void)                                                                                                                                                                                                                                             |60           |
|CFxSystem__Construct                      |0040da20|void CFxSystem__Construct(void* pThis)                                                                                                                                                                                                                               |252          |
|COnScreen__Construct                      |0040e140|void COnScreen__Construct(void* pThis)                                                                                                                                                                                                                               |48           |
|COnScreen__Reset                          |0040e170|void COnScreen__Reset(void* pThis)                                                                                                                                                                                                                                   |8            |
|COnScreen__LevelStart                     |0040e178|void COnScreen__LevelStart(void* pThis)                                                                                                                                                                                                                              |16           |
|CAnimPool__Construct                      |00448720|void CAnimPool__Construct(void* pThis)                                                                                                                                                                                                                               |116          |
|CGameDynamicLight__Construct              |00448A20|void CGameDynamicLight__Construct(void* pThis)                                                                                                                                                                                                                       |160          |
|CMatrixPool__Construct                    |00448cc0|void CMatrixPool__Construct(void* pThis, Mtx* Matricies, int nTotal)                                                                                                                                                                                                |128          |
|CParticleSystem__Construct                |00448d40|void CParticleSystem__Construct(void* pThis, void* pParticleData)                                                                                                                                                                                                   |522          |
|CScene__ConstructMap                      |00448F50|void CScene__ConstructMap(void* pThis, void* pSection, int nObjType)                                                                                                                                                                                                |460          |
|CScene__Construct                         |00449118|void CScene__Construct(CScene* pThis, void* rpData)                                                                                                                                                                                                                 |1348         |
|CScene__LevelSetup                        |0044965C|void CScene__LevelSetup(CScene* pThis)                                                                                                                                                                                                                               |260          |
|CScene__NewGame                           |0044ae08|void CScene__NewGame(CScene* pThis, void* rpData)                                                                                                                                                                                                                   |132          |
|CScene__ResetLoadSavePersistantData       |0044AE8C|void CScene__ResetLoadSavePersistantData(CScene* pThis)                                                                                                                                                                                                              |148          |
|CScene__ResetGamePersistantData           |0044af20|void CScene__ResetGamePersistantData(CScene* pThis)                                                                                                                                                                                                                  |128          |
|CScene__ConstructWarp                     |0044AFDC|void CScene__ConstructWarp(CScene* pThis)                                                                                                                                                                                                                            |108          |
|CScene__SendAllActiveLinks                |0044b45c|void CScene__SendAllActiveLinks(CScene* pThis)                                                                                                                                                                                                                       |112          |
|CSimplePool__Construct                    |0044b9c0|void CSimplePool__Construct(void* pThis)                                                                                                                                                                                                                             |300          |
|CCamera__Construct                        |0044bde0|void CCamera__Construct(CCamera* pThis)                                                                                                                                                                                                                              |16           |
|CCameraPool__NewGame                      |0044bfd8|void CCameraPool__NewGame(void* pThis, int nMaxCameras)                                                                                                                                                                                                              |516          |
|CCameraPool__Construct                    |0044C284|void CCameraPool__Construct(CCameraPool* pThis)                                                                                                                                                                                                                      |32           |
|CPlayer__LevelStart                       |0044cd5c|void CPlayer__LevelStart(void* pThis)                                                                                                                                                                                                                                |1177         |
|CPlayerPool__NewGame                      |0044d598|void CPlayerPool__NewGame(void* pThis, int nMaxPlayers)                                                                                                                                                                                                              |308          |
|CPlayerPool__LevelStart                   |0044daa8|void CPlayerPool__LevelStart(int param_1)                                                                                                                                                                                                                        |216          |
|CPlayer__HaltAllLoopingSounds             |0044ddd4|void CPlayer__HaltAllLoopingSounds(CGameObjectInstance* pThis)                                                                                                                                                                                                       |72           |
|CDecompressor__Construct                  |00242360|void CDecompressor__Construct(void)                                                                                                                                                                                                                              |1            |
|osViSwapBuffer                            |002e4e30|void osViSwapBuffer(void)                                                                                                                                                                                                                                        |8            |
|CPool__AllocateStandardBuffers            |~~80405c70~~|void CPool__AllocateStandardBuffers()                                                                                                                                                                                                                            |12           |
|CPool__Construct                          |~~80406044~~|void CPool__Construct(void* pThis)                                                                                                                                                                                                                              |1            |
|CPlayerPool__Construct                    |~~8044da48~~|void CPlayerPool__Construct(uint8_t* pThis)                                                                                                                                                                                                                          |108          |

### Memory Map

|Address|Type|Name|
|-------|----|----|
|80114974|uint32_t|bCutsceneBlackBars|
|800FB0C0|float|refresh_rate_set_PAL|
|800FB0C4|float|refresh_rate_set_NTSC|
|800FB120|float|frame_fps|
|800FB11C|float|frame_cpu_scale|
|80104E78|float|frame_increment|
|801149E0|int|nScreenWidth|
|801149E4|int|nScreenHeight|
|801149E8|float|stretchX|
|801149EC|float|stretchY|
|801149F0|int|nVideoMode|
|801149F4|int|nOldVideoMode|
|801149F8|int|nBlackoutCounter|
|801149FC|int|filter|
|80114A00|BOOL|bIsLowRes|
|80114A04|int|deflicker|
|80114A08|int[2]|nModes|
|80114A10|[CVideoVals[6]](#CVideoVals)|[VideoVals](#VideoVals)|
|80114AB8|[RenderParams[3]](#RenderParams)|[RenderVals](#RenderVals)
|801280A0|[CHeap](#CHeap)|g_heap|
|80131EEA|uint16_t|nController|
|80131F94|int8_t|nJoyX|
|80131F95|int8_t|nJoyY|
|80139330|void*|pNextFB|
|80139340|osMesg*|pMsg|
|80139350|uint32_t|next_l_fields|
|80139360|uint32_t|next_ll_fields|
|80139370|uint32_t|next_lll_fields|
|80139380|uint32_t|next_pending|
|801393A0|void*|pCurrentFB|
|801393B0|uint32_t|current_waiting|
|801393C0|uint32_t|next_waiting|
|8013D8B0|float|refreshRate|
|8013D8C0|[CEngineApp](#CEngineApp)|g_app
|8013DC70|int|levelStatus| Members part of CScene starting here; TODO: cartograph this structure
|8013DC74|int|bPersistentDataLoaded|
|8013DC78|int|levelCutsceneFlags|
|8013DD9C|uint32_t|savePersistentDataSize|
|8013DDA0|uint32_t|gamePersistentDataSize|
|8013DDA8|[CGameObjectInstance*](#CGameObjectInstance)|pActorList|
|8013DDB0|uint32_t|nNumActors|
|8013DDB4|[CPlayer*](#CPlayer)|pPlayer|
|80164778|[CPlayerPool](#CPlayerPool)|playerPool|
|801647C0|[CCameraPool](#CCameraPool)|cameraPool|
|801659B0|uint8_t|bStereo| Members part of an options struct starting here; TODO: cartograph this structure
|801659B1|uint8_t|nMusicVolume|
|801659B2|uint8_t|nSfxVolume|
|801659B3|uint8_t|nSpeechVolume|
|801659BB|uint8_t|deathmatchRadarMode|
|801659BC|uint8_t|nVideoModeCopy|
|801659C0|uint32_t|nGameMode|
|801659C4|uint32_t|unlockedSecrets|
|801659C8|uint32_t|enabledSecrets|
|801659CC|uint32_t|difficulty|
|801659D8|uint32_t|nGameModeCopy|
|801659DC|uint32_t|nScoreLimit|
|801659E0|uint32_t|nTimeLimit|
|801659E8|BOOL|bTeamDamage|
|801659EC|BOOL|bSuddenDeath|
|801659F0|uint32_t|nArena|
|80165A00|uint32_t|nWeaponPreset|
|80165A0C|uint32_t|nMPBowSetting|
|80165A10|uint32_t|nMPPistolSetting|
|80165A14|uint32_t|nMPARSetting|
|80165A18|uint32_t|nMPShotgunSetting|
|80165A1C|uint32_t|nMPVampSetting|
|80165A20|uint32_t|nMPGrenadeSetting|
|80165A24|uint32_t|nMPBoreSetting|
|80165A54|int32_t|nMPDamageScale|
|80165A58|uint32_t|nMPMaxHealth|
|80165A5C|float|mpPickupDelay|
|80165A60|float|mpHealthPickupValueScale|
|80165A64|float|mpInitialAmmoScale|
|80165A68|float|mpAmmoCapacityScale|
|80165A6C|float|mpAmmoPickupValueScale|
|80165A70|float|mpSpecialPickupValueScale|
|80165A74|float|mpGravityScale|
|80165A78|float|mpMovementSpeedScale|
|80165B10|uint32_t|mpDeathmatchMusic|
|80165B58|[COptions](#COptions)|gameOptions|
|80166120|uint32_t|next_fields| this is graphics stuff, related to stuff around 8013; probably part of a structure
|80166130|uint32_t|nDisplayLists|
|80166180|uint32_t|current_finished|
|801661E0|uint32_t|current_fields|


### Structure Definitions

|File|
|----|
|[AIFunc.h](lib/libtengine/lib/types/AIFunc.h) <a name="AIFunc"></a>|
|[AnimInfo.h](lib/libtengine/lib/types/AnimInfo.h) <a name="AnimInfo"></a>|
|[CActiveGridSection.h](lib/libtengine/lib/types/CActiveGridSection.h) <a name="CActiveGridSection"></a>|
|[CActiveLink.h](lib/libtengine/lib/types/CActiveLink.h) <a name="CActiveLink"></a>|
|[CAI.h](lib/libtengine/lib/types/CAI.h) <a name="CAI"></a>|
|[CAIModeInfo.h](lib/libtengine/lib/types/CAIModeInfo.h) <a name="CAIModeInfo"></a>|
|[CAmmo.h](lib/libtengine/lib/types/CAmmo.h) <a name="CAmmo"></a>|
|[CAnimationState.h](lib/libtengine/lib/types/CAnimationState.h) <a name="CAnimationState"></a>|
|[CAnimDrawInfo.h](lib/libtengine/lib/types/CAnimDrawInfo.h) <a name="CAnimDrawInfo"></a>|
|[CAnimNodeInfo.h](lib/libtengine/lib/types/CAnimNodeInfo.h) <a name="CAnimNodeInfo"></a>|
|[CAnimPool.h](lib/libtengine/lib/types/CAnimPool.h) <a name="CAnimPool"></a>|
|[CBarrel.h](lib/libtengine/lib/types/CBarrel.h) <a name="CBarrel"></a>|
|[CBarrelWeapon.h](lib/libtengine/lib/types/CBarrelWeapon.h) <a name="CBarrelWeapon"></a>|
|[CBoundsRect.h](lib/libtengine/lib/types/CBoundsRect.h) <a name="CBoundsRect"></a>|
|[CBulletHole.h](lib/libtengine/lib/types/CBulletHole.h) <a name="CBulletHole"></a>|
|[CButton.h](lib/libtengine/lib/types/CButton.h) <a name="CButton"></a>|
|[CCacheEntry.h](lib/libtengine/lib/types/CCacheEntry.h) <a name="CCacheEntry"></a>|
|[CCamera.h](lib/libtengine/lib/types/CCamera.h) <a name="CCamera"></a>|
|[CCameraPool.h](lib/libtengine/lib/types/CCameraPool.h) <a name="CCameraPool"></a>|
|[CCameraText.h](lib/libtengine/lib/types/CCameraText.h) <a name="CCameraText"></a>|
|[CCameraViewParams.h](lib/libtengine/lib/types/CCameraViewParams.h) <a name="CCameraViewParams"></a>|
|[CCameraViewport.h](lib/libtengine/lib/types/CCameraViewport.h) <a name="CCameraViewport"></a>|
|[CCollisionInfo.h](lib/libtengine/lib/types/CCollisionInfo.h) <a name="CCollisionInfo"></a>|
|[CContState.h](lib/libtengine/lib/types/CContState.h) <a name="CContState"></a>|
|[CDamageInfo.h](lib/libtengine/lib/types/CDamageInfo.h) <a name="CDamageInfo"></a>|
|[CDLight.h](lib/libtengine/lib/types/CDLight.h) <a name="CDLight"></a>|
|[CDynamicAnim.h](lib/libtengine/lib/types/CDynamicAnim.h) <a name="CDynamicAnim"></a>|
|[CDynamicList.h](lib/libtengine/lib/types/CDynamicList.h) <a name="CDynamicList"></a>|
|[CDynamicSimple.h](lib/libtengine/lib/types/CDynamicSimple.h) <a name="CDynamicSimple"></a>|
|[CEngineApp.h](lib/libtengine/lib/types/CEngineApp.h) <a name="CEngineApp"></a>|
|[CFrameData.h](lib/libtengine/lib/types/CFrameData.h) <a name="CFrameData"></a>|
|[CFxSystem.h](lib/libtengine/lib/types/CFxSystem.h) <a name="CFxSystem"></a>|
|[CFxTimer.h](lib/libtengine/lib/types/CFxTimer.h) <a name="CFxTimer"></a>|
|[CGameCurve.h](lib/libtengine/lib/types/CGameCurve.h) <a name="CGameCurve"></a>|
|[CGameDynamicLight.h](lib/libtengine/lib/types/CGameDynamicLight.h) <a name="CGameDynamicLight"></a>|
|[CGameObjectInstance.h](lib/libtengine/lib/types/CGameObjectInstance.h) <a name="CGameObjectInstance"></a>|
|[CGameRegion.h](lib/libtengine/lib/types/CGameRegion.h) <a name="CGameRegion"></a>|
|[CGameRumble.h](lib/libtengine/lib/types/CGameRumble.h) <a name="CGameRumble"></a>|
|[CGameSection.h](lib/libtengine/lib/types/CGameSection.h) <a name="CGameSection"></a>|
|[CGameSimpleInstance.h](lib/libtengine/lib/types/CGameSimpleInstance.h) <a name="CGameSimpleInstance"></a>|
|[CGameStaticInstance.h](lib/libtengine/lib/types/CGameStaticInstance.h) <a name="CGameStaticInstance"></a>|
|[CGameStatus.h](lib/libtengine/lib/types/CGameStatus.h) <a name="CGameStatus"></a>|
|[CHeap.h](lib/libtengine/lib/types/CHeap.h) <a name="CHeap"></a>|
|[CHeapBlock.h](lib/libtengine/lib/types/CHeapBlock.h) <a name="CHeapBlock"></a>|
|[CInstanceHeader.h](lib/libtengine/lib/types/CInstanceHeader.h) <a name="CInstanceHeader"></a>|
|[CIntelligence.h](lib/libtengine/lib/types/CIntelligence.h) <a name="CIntelligence"></a>|
|[CISet.h](lib/libtengine/lib/types/CISet.h) <a name="CISet"></a>|
|[CList.h](lib/libtengine/lib/types/CList.h) <a name="CList"></a>|
|[CLoaderEntry.h](lib/libtengine/lib/types/CLoaderEntry.h) <a name="CLoaderEntry"></a>|
|[CLoopingSoundData.h](lib/libtengine/lib/types/CLoopingSoundData.h) <a name="CLoopingSoundData"></a>|
|[CMap.h](lib/libtengine/lib/types/CMap.h) <a name="CMap"></a>|
|[CMatrixPool.h](lib/libtengine/lib/types/CMatrixPool.h) <a name="CMatrixPool"></a>|
|[CMemEntry.h](lib/libtengine/lib/types/CMemEntry.h) <a name="CMemEntry"></a>|
|[CMenu.h](lib/libtengine/lib/types/CMenu.h) <a name="CMenu"></a>|
|[CMenuPool.h](lib/libtengine/lib/types/CMenuPool.h) <a name="CMenuPool"></a>|
|[CMtxF.h](lib/libtengine/lib/types/CMtxF.h) <a name="CMtxF"></a>|
|[CNode.h](lib/libtengine/lib/types/CNode.h) <a name="CNode"></a>|
|[CNodeList.h](lib/libtengine/lib/types/CNodeList.h) <a name="CNodeList"></a>|
|[COnScreen.h](lib/libtengine/lib/types/COnScreen.h) <a name="COnScreen"></a>|
|[COptions.h](lib/libtengine/lib/types/COptions.h) <a name="COptions"></a>|
|[COverlay.h](lib/libtengine/lib/types/COverlay.h) <a name="COverlay"></a>|
|[CParticle.h](lib/libtengine/lib/types/CParticle.h) <a name="CParticle"></a>|
|[CParticleSystem.h](lib/libtengine/lib/types/CParticleSystem.h) <a name="CParticleSystem"></a>|
|[CPathTrack.h](lib/libtengine/lib/types/CPathTrack.h) <a name="CPathTrack"></a>|
|[CPlane.h](lib/libtengine/lib/types/CPlane.h) <a name="CPlane"></a>|
|[CPlayer.h](lib/libtengine/lib/types/CPlayer.h) <a name="CPlayer"></a>|
|[CPlayerContState.h](lib/libtengine/lib/types/CPlayerContState.h) <a name="CPlayerContState"></a>|
|[CPlayerLoadSaveData.h](lib/libtengine/lib/types/CPlayerLoadSaveData.h) <a name="CPlayerLoadSaveData"></a>|
|[CPlayerOptions.h](lib/libtengine/lib/types/CPlayerOptions.h) <a name="CPlayerOptions"></a>|
|[CPlayerOverlay.h](lib/libtengine/lib/types/CPlayerOverlay.h) <a name="CPlayerOverlay"></a>|
|[CPlayerPool.h](lib/libtengine/lib/types/CPlayerPool.h) <a name="CPlayerPool"></a>|
|[CQuaternion.h](lib/libtengine/lib/types/CQuaternion.h) <a name="CQuaternion"></a>|
|[CRandomShortPair.h](lib/libtengine/lib/types/CRandomShortPair.h) <a name="CRandomShortPair"></a>|
|[CROMCorner.h](lib/libtengine/lib/types/CROMCorner.h) <a name="CROMCorner"></a>|
|[CROMCurve.h](lib/libtengine/lib/types/CROMCurve.h) <a name="CROMCurve"></a>|
|[CROMDynamicLight.h](lib/libtengine/lib/types/CROMDynamicLight.h) <a name="CROMDynamicLight"></a>|
|[CROMHotPoint.h](lib/libtengine/lib/types/CROMHotPoint.h) <a name="CROMHotPoint"></a>|
|[CROMInitialOrientation.h](lib/libtengine/lib/types/CROMInitialOrientation.h) <a name="CROMInitialOrientation"></a>|
|[CROMLevel.h](lib/libtengine/lib/types/CROMLevel.h) <a name="CROMLevel"></a>|
|[CROMLink.h](lib/libtengine/lib/types/CROMLink.h) <a name="CROMLink"></a>|
|[CROMNode.h](lib/libtengine/lib/types/CROMNode.h) <a name="CROMNode"></a>|
|[CROMNodeIndex.h](lib/libtengine/lib/types/CROMNodeIndex.h) <a name="CROMNodeIndex"></a>|
|[CROMObjectInfo.h](lib/libtengine/lib/types/CROMObjectInfo.h) <a name="CROMObjectInfo"></a>|
|[CROMParticle.h](lib/libtengine/lib/types/CROMParticle.h) <a name="CROMParticle"></a>|
|[CROMParticleColor.h](lib/libtengine/lib/types/CROMParticleColor.h) <a name="CROMParticleColor"></a>|
|[CROMParticleDir.h](lib/libtengine/lib/types/CROMParticleDir.h) <a name="CROMParticleDir"></a>|
|[CROMParticleGeneral.h](lib/libtengine/lib/types/CROMParticleGeneral.h) <a name="CROMParticleGeneral"></a>|
|[CROMParticleImpact.h](lib/libtengine/lib/types/CROMParticleImpact.h) <a name="CROMParticleImpact"></a>|
|[CROMParticleOffset.h](lib/libtengine/lib/types/CROMParticleOffset.h) <a name="CROMParticleOffset"></a>|
|[CROMParticlePhysics.h](lib/libtengine/lib/types/CROMParticlePhysics.h) <a name="CROMParticlePhysics"></a>|
|[CROMParticleRot.h](lib/libtengine/lib/types/CROMParticleRot.h) <a name="CROMParticleRot"></a>|
|[CROMParticleScale.h](lib/libtengine/lib/types/CROMParticleScale.h) <a name="CROMParticleScale"></a>|
|[CROMParticleSineWave.h](lib/libtengine/lib/types/CROMParticleSineWave.h) <a name="CROMParticleSineWave"></a>|
|[CROMRumble.h](lib/libtengine/lib/types/CROMRumble.h) <a name="CROMRumble"></a>|
|[CROMSkyLayer.h](lib/libtengine/lib/types/CROMSkyLayer.h) <a name="CROMSkyLayer"></a>|
|[CROMSwoosh.h](lib/libtengine/lib/types/CROMSwoosh.h) <a name="CROMSwoosh"></a>|
|[CROMSwooshPoint.h](lib/libtengine/lib/types/CROMSwooshPoint.h) <a name="CROMSwooshPoint"></a>|
|[CROMWarpPoint.h](lib/libtengine/lib/types/CROMWarpPoint.h) <a name="CROMWarpPoint"></a>|
|[CRumblePool.h](lib/libtengine/lib/types/CRumblePool.h) <a name="CRumblePool"></a>|
|[CScene.h](lib/libtengine/lib/types/CScene.h) <a name="CScene"></a>|
|[CShake.h](lib/libtengine/lib/types/CShake.h) <a name="CShake"></a>|
|[CShakeAxis.h](lib/libtengine/lib/types/CShakeAxis.h) <a name="CShakeAxis"></a>|
|[CSimplePool.h](lib/libtengine/lib/types/CSimplePool.h) <a name="CSimplePool"></a>|
|[CSkyLayer.h](lib/libtengine/lib/types/CSkyLayer.h) <a name="CSkyLayer"></a>|
|[CSkySystem.h](lib/libtengine/lib/types/CSkySystem.h) <a name="CSkySystem"></a>|
|[CSun.h](lib/libtengine/lib/types/CSun.h) <a name="CSun"></a>|
|[CSunFrameData.h](lib/libtengine/lib/types/CSunFrameData.h) <a name="CSunFrameData"></a>|
|[CSwoosh.h](lib/libtengine/lib/types/CSwoosh.h) <a name="CSwoosh"></a>|
|[CSwooshEdge.h](lib/libtengine/lib/types/CSwooshEdge.h) <a name="CSwooshEdge"></a>|
|[CUSet.h](lib/libtengine/lib/types/CUSet.h) <a name="CUSet"></a>|
|[CVector3.h](lib/libtengine/lib/types/CVector3.h) <a name="CVector3"></a>|
|[CVideoVals.h](lib/libtengine/lib/types/CVideoVals.h) <a name="CVideoVals"></a>|
|[CWeapon.h](lib/libtengine/lib/types/CWeapon.h) <a name="CWeapon"></a>|
|[CWeaponAmmoInfo.h](lib/libtengine/lib/types/CWeaponAmmoInfo.h) <a name="CWeaponAmmoInfo"></a>|
|[CWeaponInfo.h](lib/libtengine/lib/types/CWeaponInfo.h) <a name="CWeaponInfo"></a>|
|[health_helper.h](lib/libtengine/lib/types/health_helper.h) <a name="health_helper"></a>|
|[RenderParams.h](lib/libtengine/lib/types/RenderParams.h) <a name="RenderParams"></a>|