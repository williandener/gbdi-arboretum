#ifndef __STMULTIPLEPAGEMANAGER_H
#define __STMULTIPLEPAGEMANAGER_H

#include <arboretum/stPageManager.h>
#include <vector>

template <class PageManager>
class stMultiplePageManager : public stPageManager {
public:
    stMultiplePageManager(const string &fileName,
                          u_int32_t pagesPerPM,
                          u_int32_t pageSize);

    stMultiplePageManager(const string &fileName,
                          u_int32_t pagesPerPM);

    virtual ~stMultiplePageManager();

    virtual bool IsEmpty();

    virtual stPage* GetHeaderPage();

    virtual stPage* GetPage(u_int32_t pageID);

    virtual void ReleasePage(stPage *page);

    virtual stPage* GetNewPage();

    virtual void WritePage(stPage *page);

    virtual void WriteHeaderPage(stPage *headerPage);

    virtual void DisposePage(stPage *page);

    virtual u_int32_t GetMinimumPageSize();

    virtual u_int32_t GetPageCount();

    virtual void ResetStatistics();

private:
    string fileName;

    u_int32_t pagesPerPM;

    u_int32_t pageCount;

    vector<PageManager*> PMs;

    u_int32_t GetCorrespondentPM(u_int32_t logicalPageID);

    u_int32_t GetActualPageID(u_int32_t logicalPageID);
};

#include "stMultiplePageManager-inl.h"

#endif
