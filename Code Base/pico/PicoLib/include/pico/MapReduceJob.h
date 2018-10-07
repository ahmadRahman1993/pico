#ifndef __PICO_MAPREDUCEJOB_H__
#define __PICO_MAPREDUCEJOB_H__

#include <vector>

namespace pico
{
  class Chunk;
  class Combiner;
  class Mapper;
  class PartialReducer;
  class Sorter;
  class Reducer;
  class SerializedItemCollection;
  class MapReduceJob
  {
    protected:
      Combiner        * combiner;
      Mapper          * mapper;
      PartialReducer  * partialReducer;
      Sorter          * sorter;
      Reducer         * reducer;
      int commRank, commSize, deviceNum;

      void setDevice();
      virtual void map() = 0;
      virtual void sort() = 0;
      virtual void reduce() = 0;
      void collectTimings();
    public:
      MapReduceJob(int & argc, char **& argv);
      virtual ~MapReduceJob();

      inline Combiner        * getCombiner()        { return combiner;        }
      inline Mapper          * getMapper()          { return mapper;          }
      inline PartialReducer  * getPartialReducer()  { return partialReducer;  }
      inline Sorter          * setSorter()          { return sorter;          }
      inline Reducer         * getReducer()         { return reducer;         }
      inline int               getDeviceNumber()    { return deviceNum;       }

      inline void setCombiner      (Combiner       * const pCombiner)       { combiner       = pCombiner;       }
      inline void setMapper        (Mapper         * const pMapper)         { mapper         = pMapper;         }
      inline void setPartialReducer(PartialReducer * const pPartialReducer) { partialReducer = pPartialReducer; }
      inline void setSorter        (Sorter         * const pSorter)         { sorter         = pSorter;         }
      inline void setReducer       (Reducer        * const pReducer)        { reducer        = pReducer;        }

      virtual void addInput(Chunk * chunk) = 0;
      virtual void execute() = 0;
  };
}

#endif
