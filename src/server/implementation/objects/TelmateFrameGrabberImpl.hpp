#ifndef __TELMATE_FRAME_GRABBER_IMPL_HPP__
#define __TELMATE_FRAME_GRABBER_IMPL_HPP__

#include "OpenCVFilterImpl.hpp"
#include "TelmateFrameGrabber.hpp"
#include <EventHandler.hpp>
#include <boost/property_tree/ptree.hpp>
#include "TelmateFrameGrabberOpenCVImpl.hpp"

namespace kurento
{
namespace module
{
namespace telmateframegrabber
{
class TelmateFrameGrabberImpl;
} /* telmateframegrabber */
} /* module */
} /* kurento */

namespace kurento
{
void Serialize (std::shared_ptr<kurento::module::telmateframegrabber::TelmateFrameGrabberImpl> &object, JsonSerializer &serializer);
} /* kurento */

namespace kurento
{
class MediaPipelineImpl;
} /* kurento */

namespace kurento
{
namespace module
{
namespace telmateframegrabber
{

class TelmateFrameGrabberImpl : public OpenCVFilterImpl, public virtual TelmateFrameGrabber, public virtual TelmateFrameGrabberOpenCVImpl
{

public:

  TelmateFrameGrabberImpl (const boost::property_tree::ptree &config, std::shared_ptr<MediaPipeline> mediaPipeline);

  virtual ~TelmateFrameGrabberImpl () {};

  int cleanup ();
  int getSnapInterval ();
  void setSnapInterval (int snapInterval);
  std::string getStoragePath ();
  void setStoragePath (const std::string &path);
  void setWebRtcEpName (const std::string &epName);
  void setOutputFormat (int outputFormat);
  void setMonitorTimeoutSec(int timeout);
  int getMonitorTimeoutSec();
  void setSessionUUID(const std::string &puuid);
  std::string getSessionUUID();
  /* Next methods are automatically implemented by code generator */
  virtual bool connect (const std::string &eventType, std::shared_ptr<EventHandler> handler);
  virtual void invoke (std::shared_ptr<MediaObjectImpl> obj,
                       const std::string &methodName, const Json::Value &params,
                       Json::Value &response);

  virtual void Serialize (JsonSerializer &serializer);

private:

  class StaticConstructor
  {
  public:
    StaticConstructor();
  };

  static StaticConstructor staticConstructor;

};

} /* telmateframegrabber */
} /* module */
} /* kurento */

#endif /*  __TELMATE_FRAME_GRABBER_IMPL_HPP__ */
