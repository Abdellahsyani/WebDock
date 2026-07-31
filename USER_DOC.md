# WebDock User Guide

This guide is for users/operators who want to run and interact with WebDock services.

### 1) What You Can Do as a User

With WebDock, you can:

    Start all project services in one command.
    Stop and restart services safely.
    Monitor logs.
    Access hosted web interfaces/APIs through exposed ports.

### 2) Prerequisites

Before running WebDock:

    Install Docker
    Install Docker Compose plugin
    Install Make

Check installation: docker --version docker compose version make --version
### 3) Run the Project

From repository root: make

This builds images (if needed) and starts the full stack.
### 4) Access Services

After startup:

    Run docker ps to list running containers.
    Identify published ports.
    Open your browser or API client using http://localhost:<port>.

### 5) Common User Commands

    Start/build stack: make

    Stop stack: make down

    Rebuild from scratch: make re

    Full cleanup: make fclean

### 6) View Logs

    All services: docker compose logs -f

    Single service: docker compose logs -f <service_name>

### 7) Health Checks

Basic checks:

    Containers are running: docker ps
    No restart loops: docker ps --format '{{.Names}} {{.Status}}'
    Endpoints return responses (curl or browser)

```Example: curl -I http://localhost:<port>```
### 8) Data & Persistence

WebDock uses Docker volumes for persistent data. This means:

    Restarting containers usually keeps data.
    Full cleanup commands may remove data depending on implementation.

If data matters, back up before make fclean.
### 9) Troubleshooting

If services are not reachable:

    Confirm containers are up (docker ps).
    Check logs (docker compose logs -f).
    Verify port conflicts.
    Rebuild (make re).

If Docker permissions fail (Linux):

    Ensure your user belongs to the docker group.

### 10) Safe Usage Tips

    Avoid editing container internals directly.
    Prefer changing configuration/files in the repo and rebuilding.
    Keep local environment clean to avoid stale artifacts.
