#ifndef CONTEXT_H
#define CONTEXT_H

class Context 
{
  Context(const Context& other);
  const Context& operator=(const Context& other);

 protected:
  virtual void finish(int r) = 0;

  // variant of finish that is safe to call "synchronously."  override should
  // return true.
  virtual bool sync_finish(int r) {
    return false;
  }

 public:
  Context() {}

  virtual ~Context() {} 

  virtual void complete(int r) {
    finish(r);
    delete this;
  }

  virtual bool sync_complete(int r) {
    if (sync_finish(r)) {
      delete this;
      return true;
    }
    return false;
  }
};

#endif
