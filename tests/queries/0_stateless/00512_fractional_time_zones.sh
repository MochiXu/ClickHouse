#!/usr/bin/env bash

CURDIR=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)
# shellcheck source=../shell_config.sh
. "$CURDIR"/../shell_config.sh

TZ=Asia/Istanbul ${CLICKHOUSE_LOCAL} --query="SELECT toDateTime('1990-10-19 00:00:00')"
TZ=Asia/Colombo ${CLICKHOUSE_LOCAL} --query="SELECT toDateTime('1990-10-19 00:00:00')"
TZ=Asia/Kathmandu ${CLICKHOUSE_LOCAL} --query="SELECT toDateTime('1990-10-19 00:00:00')"
