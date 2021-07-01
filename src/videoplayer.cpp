#include "videoplayer.h"

#include <iostream>
#include <algorithm>
#include <cstdlib>

void VideoPlayer::numberOfVideos()
{
  std::cout << mVideoLibrary.getVideos().size() << " videos in the library"
            << std::endl;
}

void VideoPlayer::showAllVideos()
{
  std::vector<std::string> videosStringVector;
  std::string videoIdNameTagString;
  std::cout << "Here's a list of all available videos:" << std::endl;

  for (Video itr : mVideoLibrary.getVideos())
  {
    std::vector<std::string> temp = itr.getTags();

    videoIdNameTagString = itr.getTitle() + " (" + itr.getVideoId() + ") [";

    for (std::string stItr : temp)
    {
      videoIdNameTagString.append(stItr + " ");
    }

    if (videoIdNameTagString.back() == ' ')
      videoIdNameTagString.pop_back();

    videoIdNameTagString += "]";
    videosStringVector.push_back(videoIdNameTagString);
    videoIdNameTagString.clear();
  }

  std::sort(videosStringVector.begin(), videosStringVector.end());

  for (std::string stItr : videosStringVector)
  {
    std::cout << stItr << std::endl;
  }
  videosStringVector.clear();
}

void VideoPlayer::playVideo(const std::string &videoId)
{
  bool videoFound = false;
  for (Video itr : mVideoLibrary.getVideos())
  {
    if (itr.getVideoId() == videoId)
    {
      videoFound = true;
      break;
    }
  }
  if (!videoFound)
  {
    std::cout << "Cannot play video: Video does not exist" << std::endl;
    return;
  }
  else
  {
    if (!videoPlaying)
    {
      videoPlaying = true;
      playingVideoName = videoId;
      for (Video itr : mVideoLibrary.getVideos())
      {
        if (itr.getVideoId() == videoId)
        {
          std::cout << "Playing video: " << itr.getTitle() << std::endl;
          return;
        }
      }
    }
    else
    {
      for (Video itr : mVideoLibrary.getVideos())
      {
        if (itr.getVideoId() == playingVideoName)
        {
          std::cout << "Stopping video: " << itr.getTitle() << std::endl;
          break;
        }
      }
      for (Video itr : mVideoLibrary.getVideos())
      {
        if (itr.getVideoId() == videoId)
        {
          std::cout << "Playing video: " << itr.getTitle() << std::endl;
          return;
        }
      }
    }
  }
}

void VideoPlayer::stopVideo()
{
  if (!videoPlaying)
  {
    std::cout << "Cannot stop video: No video is currently playing" << std::endl;
  }
  else
  {
    for (Video itr : mVideoLibrary.getVideos())
    {
      if (itr.getVideoId() == playingVideoName)
      {
        std::cout << "Stopping video: " << itr.getTitle() << std::endl;
        videoPlaying = false;
        return;
      }
    }
  }
}

void VideoPlayer::playRandomVideo()
{
  srand(time(NULL));
  if (mVideoLibrary.getVideos().size() == 0)
  {
    std::cout << "No videos available" << std::endl;
    return;
  }
  int randomId = rand() % mVideoLibrary.getVideos().size();
  std::vector<Video> videosVector = mVideoLibrary.getVideos();
  Video videoObject = videosVector[randomId];
  if (videoPlaying)
  {
    for (Video itr : mVideoLibrary.getVideos())
    {
      if (itr.getVideoId() == playingVideoName)
      {
        std::cout << "Stopping video: " << itr.getTitle() << std::endl;
        std::cout << "Playing video: " << videoObject.getTitle() << std::endl;
        playingVideoName = videoObject.getVideoId();
        return;
      }
    }
  }
  else
  {
    std::cout << "Playing video: " << videoObject.getTitle() << std::endl;
    playingVideoName = videoObject.getVideoId();
  }
}

void VideoPlayer::pauseVideo()
{
  std::cout << "pauseVideo needs implementation" << std::endl;
}

void VideoPlayer::continueVideo()
{
  std::cout << "continueVideo needs implementation" << std::endl;
}

void VideoPlayer::showPlaying()
{
  std::cout << "showPlaying needs implementation" << std::endl;
}

void VideoPlayer::createPlaylist(const std::string &playlistName)
{
  std::cout << "createPlaylist needs implementation" << std::endl;
}

void VideoPlayer::addVideoToPlaylist(const std::string &playlistName,
                                     const std::string &videoId)
{
  std::cout << "addVideoToPlaylist needs implementation" << std::endl;
}

void VideoPlayer::showAllPlaylists()
{
  std::cout << "showAllPlaylists needs implementation" << std::endl;
}

void VideoPlayer::showPlaylist(const std::string &playlistName)
{
  std::cout << "showPlaylist needs implementation" << std::endl;
}

void VideoPlayer::removeFromPlaylist(const std::string &playlistName,
                                     const std::string &videoId)
{
  std::cout << "removeFromPlaylist needs implementation" << std::endl;
}

void VideoPlayer::clearPlaylist(const std::string &playlistName)
{
  std::cout << "clearPlaylist needs implementation" << std::endl;
}

void VideoPlayer::deletePlaylist(const std::string &playlistName)
{
  std::cout << "deletePlaylist needs implementation" << std::endl;
}

void VideoPlayer::searchVideos(const std::string &searchTerm)
{
  std::cout << "searchVideos needs implementation" << std::endl;
}

void VideoPlayer::searchVideosWithTag(const std::string &videoTag)
{
  std::cout << "searchVideosWithTag needs implementation" << std::endl;
}

void VideoPlayer::flagVideo(const std::string &videoId)
{
  std::cout << "flagVideo needs implementation" << std::endl;
}

void VideoPlayer::flagVideo(const std::string &videoId, const std::string &reason)
{
  std::cout << "flagVideo needs implementation" << std::endl;
}

void VideoPlayer::allowVideo(const std::string &videoId)
{
  std::cout << "allowVideo needs implementation" << std::endl;
}
