#define CATCH_CONFIG_MAIN

#include "../test/catch.hpp"
#include <iostream>
#include <vector>
#include "netease.h"
#include "IsrafilBase/IsrafilBase.h"

using namespace Israfil::Netease;
using namespace Israfil::SongBase;
using std::vector;


TEST_CASE("Israfil::Netease Basic Tests - Search", "Netease") {
  // std::cout<<base64::encode("LOVE") <<std::endl;
  // std::cout<<MD5("LOVE").toStr() <<std::endl;
  Netease *ne = new Netease();
  SongList sl;
  ne->SearchSong("盛世回首", sl);
  ne->FillLyricsURL(sl[0]);
  std::cout<< "First Lyrics::::: " << ne->GetLyrics(sl[0]) << std::endl;
  std::cout << ne->encryptID("7947270045631279") << std::endl;

  SongListInfoList slil;
  ne->GetUserSongList("46123345", slil);
  dbg(slil.size());
  dbg(slil[3].slName);
  dbg(SongListInfoListToJson(slil));
  SongListDetail tmpSLD;
  ne->GetSongListDetail("98552501", tmpSLD);
  dbg(SongListToJson(tmpSLD.slTracks));
}
