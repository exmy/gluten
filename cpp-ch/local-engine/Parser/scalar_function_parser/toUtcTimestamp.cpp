/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <Parser/scalar_function_parser/utcTimestampTransform.h>

namespace local_engine
{

class FunctionParserToUtcTimestamp : public FunctionParserUtcTimestampTransform
{
public:
    explicit FunctionParserToUtcTimestamp(ParserContextPtr parser_context_) : FunctionParserUtcTimestampTransform(parser_context_) { }
    ~FunctionParserToUtcTimestamp() override = default;

    static constexpr auto name = "to_utc_timestamp";
    String getCHFunctionName(const substrait::Expression_ScalarFunction &) const override { return "to_utc_timestamp"; }
    String getName() const override { return "to_utc_timestamp"; }
};

static FunctionParserRegister<FunctionParserToUtcTimestamp> toUtcTimestamp;
}
