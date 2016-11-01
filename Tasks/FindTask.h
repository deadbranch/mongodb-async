#ifndef MONGODB_ASYNC_FINDTASK_H
#define MONGODB_ASYNC_FINDTASK_H

#include "../BaseHeader.h"
#include "../MongoDbHeader.h"
#include "../TaskContext.h"

typedef function<void(bool err, optional<document_vector_ptr>)> FindCompletionHandler;

class FindTask: public TaskContext {
public:
    string collection;
    document_ptr query;
    FindCompletionHandler completionHandler;
    FindTask(const FindTask& oth) = delete;
    FindTask(FindTask&& oth) = delete;
    FindTask(io_service& targetService, string collection, document_ptr query, FindCompletionHandler completionHandler)
            : TaskContext(targetService), collection(collection), query(query), completionHandler(completionHandler) {
    }
};

#endif //MONGODB_ASYNC_FINDTASK_H